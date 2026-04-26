const IAnimal = @import("animal.zig").IAnimal;
const std = @import("std");

pub const Pig = struct {
    name: []const u8,
    age: i32,

    const virtual = struct {
        const VTable: IAnimal.VTable = .{
            .makeNoise = makeNoise,
            .getName = getName,
            .getAge = getAge,
            .getLegCount = getLegCount,
        };

        fn makeNoise() void {
            std.debug.print("Oink!", .{});
        }

        fn getName(ptr: *anyopaque) []const u8 {
            const self: *Pig = @ptrCast(@alignCast(ptr));
            return self.name;
        }

        fn getAge(ptr: *anyopaque) i32 {
            const self: *Pig = @ptrCast(@alignCast(ptr));
            return self.age;
        }

        fn getLegCount() i32 {
            return 4;
        }
    };

    pub fn interface(self: *Pig) IAnimal {
        return .{
            .ptr = self,
            .vtable = &virtual.VTable,
        };
    }
};