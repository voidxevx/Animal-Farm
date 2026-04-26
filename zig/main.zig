const std = @import("std");
const Pig = @import("pig.zig").Pig;
const Chicken = @import("chicken.zig").Chicken;
const Farm = @import("farm.zig").Farm;

pub fn main() !void {
    var cesar: Pig = .{ .name = "Cesar", .age = 45 };
    var cluck: Chicken = .{ .name = "Mother-clucker", .age = 5 };

    const gpa = std.heap.page_allocator;
    var farm: Farm = try .init(gpa);
    defer farm.deinit(gpa);

    farm.addAnimal(cesar.interface());
    farm.addAnimal(cluck.interface());

    std.debug.print("{f}", .{farm});
}