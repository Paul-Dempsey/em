const std = @import("std");
const max_align = @import("builtin").target.maxIntAlignment();
const pad_amount = std.mem.alignForward(usize, @sizeOf(usize), max_align);

// must be set before using external
var allocator: std.mem.Allocator = undefined;

pub fn SetAllocator(alloc: std.mem.Allocator) void {
    allocator = alloc;
}

pub export fn AllocMemory(size: usize) ?[*]align(max_align) u8 {
    const slice = allocator.alignedAlloc(u8, max_align, pad_amount + size) catch return null;
    // store the size before the data
    @as(*usize, @ptrCast(slice.ptr)).* = size;
    return slice.ptr + pad_amount;
}

pub export fn ReAllocMemory(maybe_ptr: ?[*]align(max_align) u8, new_size: usize) ?[*]align(max_align) u8 {
    if (maybe_ptr) |ptr| {
        const orig_ptr = ptr - pad_amount;
        const orig_size = @as(*const usize, @ptrCast(orig_ptr)).*;
        const orig_slice = orig_ptr[0..(pad_amount + orig_size)];
        // realloc will take the alignment from the type of the old slice which is why we don't have
        // "aligned realloc" here or anything
        const new_slice = allocator.realloc(orig_slice, pad_amount + new_size) catch return null;
        @as(*usize, @ptrCast(new_slice.ptr)).* = new_size;
        return new_slice.ptr + pad_amount;
    } else return AllocMemory(new_size);
}

pub export fn FreeMemory(maybe_ptr: ?[*]align(max_align) u8) void {
    // free(NULL) should work and do nothing
    if (maybe_ptr) |ptr| {
        const orig_ptr = ptr - pad_amount;
        const orig_size = @as(*const usize, @ptrCast(orig_ptr)).*;
        const orig_slice = orig_ptr[0..(pad_amount + orig_size)];
        allocator.free(orig_slice);
    }
}
