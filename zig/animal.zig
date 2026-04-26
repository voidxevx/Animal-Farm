
pub const IAnimal = struct {
    ptr: *anyopaque,
    vtable: *const VTable,

    pub const VTable = struct {
        makeNoise: *const fn() void,
        getName: *const fn(*anyopaque) []const u8,
        getAge: *const fn(*anyopaque) i32,
        getLegCount: *const fn() i32,
    };

    pub fn makeNoise(self: IAnimal) void {
        self.vtable.makeNoise();
    }

    pub fn getName(self: IAnimal) []const u8 {
        return self.vtable.getName(self.ptr);
    }

    pub fn getAge(self: IAnimal) i32 {
        return self.vtable.getAge(self.ptr);
    }

    pub fn getLegCount(self: IAnimal) i32 {
        return self.vtable.getLegCount();
    }
};