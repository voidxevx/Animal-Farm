const IAnimal = @import("animal.zig").IAnimal;
const std = @import("std");

pub const Chicken = struct {
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
            std.debug.print("Cluck!", .{});
        }

        fn getName(ptr: *anyopaque) []const u8 {
            const self: *Chicken = @ptrCast(@alignCast(ptr));
            return self.name;
        }

        fn getAge(ptr: *anyopaque) i32 {
            const self: *Chicken = @ptrCast(@alignCast(ptr));
            return self.age;
        }

        fn getLegCount() i32 {
            return 2;
        }
    };

    pub fn interface(self: *Chicken) IAnimal {
        return .{
            .ptr = self,
            .vtable = &virtual.VTable,
        };
    }
};