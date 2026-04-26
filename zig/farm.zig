const IAnimal = @import("animal.zig").IAnimal;
const std = @import("std");

pub const Farm = struct {
    const FARM_CAPACITY: usize = 16;

    animals: []IAnimal,
    animal_count: usize = 0,

    pub fn init(gpa: std.mem.Allocator) !Farm {
        return .{
            .animals = try gpa.alloc(IAnimal, FARM_CAPACITY)
        };
    }

    pub fn deinit(self: *Farm, gpa: std.mem.Allocator) void {
        gpa.free(self.animals);
    }

    pub fn addAnimal(self: *Farm, animal: IAnimal) void {
        self.*.animals[self.animal_count] = animal;
        self.*.animal_count += 1;
    }

    pub fn format(self: *const Farm, writer: *std.io.Writer) std.Io.Writer.Error!void {
        try  writer.print("Animals:\n", .{});
        for (0..self.animal_count) |i| {
            const animal = self.animals[i];
            try writer.print("\t{s}, age: {d}\n", .{animal.getName(), animal.getAge()});
        }
    }
};