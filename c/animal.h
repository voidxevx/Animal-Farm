#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct
AnimalVTable {

    void (*makeNoise)();
    const char *(*getName)(void*);
    int (*getAge)(void*);
    int (*getLegCount)();

} AnimalVTable;

typedef struct
IAnimal {
    void *ptr;
    AnimalVTable *vtable;
} IAnimal;

void 
makeNoise(IAnimal self) {
    self.vtable->makeNoise();
}

const char 
*getName(IAnimal self) {
    return self.vtable->getName(self.ptr);
}

int 
getAge(IAnimal self) {
    return self.vtable->getAge(self.ptr);
}

int 
getLegCount(IAnimal self) {
    return self.vtable->getLegCount();
}

#endif