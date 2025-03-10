const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});
    const exe_name = "em-tool";

    const em_lib = b.addStaticLibrary(.{
        .name = "em-lib",
        .target = target,
        .optimize = optimize,
        .version = .{ .major = 0, .minor = 1, .patch = 0 },
        .link_libc = false,
    });
    em_lib.addIncludePath(b.path("src/em-lib"));
    em_lib.installHeader(b.path("src/em-lib/em-lib.h"), "emlib.h");
    em_lib.installHeadersDirectory(b.path("src/em-lib/include"), "include", .{});
    em_lib.addCSourceFiles(.{
        .root = b.path("src/em-lib/src"),
        .files = &.{
            "em-compressor.cpp",
            "em-hardware.cpp",
            "em-macro.cpp",
            "em-matrix.cpp",
            "em-matrix-midi.cpp",
            "em-matrix-wrap.cpp",
            "em-pedal.cpp",
            "em-recirculator.cpp",
            "em-rounding.cpp",
            "midi-file.cpp",
            "midi-message.cpp",
        },
    });
    b.installArtifact(em_lib);

    const exe = b.addExecutable(.{
        .name = exe_name,
        .root_source_file = b.path("src/main.zig"),
        .target = target,
        .optimize = optimize,
        .link_libc = false,
    });
    exe.addIncludePath(b.path("src"));
    exe.linkLibrary(em_lib);
    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());

    // This allows the user to pass arguments to the application in the build
    // command itself, like this: `zig build run -- arg1 arg2 etc`
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    // This creates a build step. It will be visible in the `zig build --help` menu,
    // and can be selected like this: `zig build run`
    // This will evaluate the `run` step rather than the default, which is "install".
    const run_step = b.step("run", "Run " ++ exe_name);
    run_step.dependOn(&run_cmd.step);

    const exe_unit_tests = b.addTest(.{
        .root_source_file = b.path("src/main.zig"),
        .target = target,
        .optimize = optimize,
    });

    const run_exe_unit_tests = b.addRunArtifact(exe_unit_tests);

    // Similar to creating the run step earlier, this exposes a `test` step to
    // the `zig build --help` menu, providing a way for the user to request
    // running the unit tests.
    const test_step = b.step("test", "Run unit tests");
    //test_step.dependOn(&run_lib_unit_tests.step);
    test_step.dependOn(&run_exe_unit_tests.step);
}
