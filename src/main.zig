const std = @import("std");
const em_lib = @cImport(@cInclude("em-lib/em-lib.h"));
const c_alloc = @import("c-alloc.zig");

fn c_bool_str(f: u8) [:0]const u8 {
    return if (f != 0) "true" else "false";
}
fn maybe_ascii(byte: u8) u8 {
    if (byte < 32) return '-';
    if (byte > 127) return '-';
    return byte;
}

fn status_name(status: u8) []const u8 {
    switch (status & em_lib.STATUS_MASK) {
        em_lib.MidiStatus_NoteOff => return "Note Off",
        em_lib.MidiStatus_NoteOn => return "Note On",
        em_lib.MidiStatus_PolyKeyPressure => return "Poly Key Pressure",
        em_lib.MidiStatus_CC => return "CC",
        em_lib.MidiStatus_ProgramChange => return "Program change",
        em_lib.MidiStatus_ChannelPressure => return "Channel Pressure",
        em_lib.MidiStatus_PitchBend => return "Pitch Bend",
        em_lib.MidiStatus_SysEx => return "SysEx",
        else => return "[OTHER]",
    }
}

fn midi_handler(_: ?*anyopaque, msg: em_lib.PackedMidiMessage) callconv(.C) u8 {
    const status: u8 = em_lib.midi_status(msg);
    const channel: u8 = em_lib.midi_channel(msg);
    std.debug.print("ch{d:0>2} {s} {d} {d} ({c}{c})\n", .{ channel, status_name(status), msg.bytes.data1, msg.bytes.data2, maybe_ascii(msg.bytes.data1), maybe_ascii(msg.bytes.data2) });
    return 1;
}

pub fn main() !void {
    std.debug.print("em-tool: [options] <in-file> -out:<out-file>\n", .{});

    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = if (std.debug.runtime_safety)
        gpa.allocator()
    else
        std.heap.c_allocator;
    defer std.debug.assert(gpa.deinit() == .ok);
    c_alloc.SetAllocator(allocator);

    const stdout = std.io.getStdOut().writer();

    if (em_lib.CreateMatrix()) |em| {
        defer c_alloc.FreeMemory(@ptrCast(@alignCast(em)));
    }
    const preset_path = "C:/Haken Editor 1034/HE/Firmware/SysPresets/Continuum/Acrylic Clock 2.mid";
    const in_file = try std.fs.openFileAbsolute(preset_path, .{ .mode = .read_only });
    defer in_file.close();

    const buf = try in_file.readToEndAlloc(allocator, 10 * 1024);
    defer allocator.free(buf);

    const e = em_lib.ParseMidiFileData(@truncate(buf.len), buf.ptr, null, midi_handler);
    switch (e) {
        em_lib.MF_Ok => {
            std.debug.print("-- Parsed Ok --\n", .{});
        },
        em_lib.MF_InvalidMidiFile => {
            std.debug.print("-- InvalidMidiFile --\n", .{});
        },
        em_lib.MF_InsufficientData => {
            std.debug.print("-- InsufficientData --\n", .{});
        },
        else => {
            std.debug.print("-- Other {d} --\n", .{e});
        },
    }
    try stdout.print("{s}\n", .{"g'bye"});
}
