const std = @import("std");
const em = @cImport(@cInclude("em-lib/em-lib.h"));

pub fn main() !void {
    std.debug.print("em-tool: [options] <in-file> -out:<out-file>\n", .{});

    const stdout = std.io.getStdOut().writer();

    const msg = em.MakeNoteOn(1, 60, 120);
    try stdout.print("{s}\n", .{std.fmt.bytesToHex(std.mem.asBytes(&msg), .upper)});
}
