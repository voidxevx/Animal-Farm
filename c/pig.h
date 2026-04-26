#ifndef PIG_ANIMAL_H
#define PIG_ANIMAL_H

#include <stdio.h>
#include "animal.h"

typedef struct 
Pig {
    const char *name;
    int age;
} Pig;

void
Pig_makeNoise() {
    printf("Oink!");
}

const char 
*Pig_getName(void *ptr) {
    Pig *self = (Pig*)ptr;
    return self->name;
}

int
Pig_getAge(void *ptr) {
    Pig *self = (Pig*)ptr;
    return self->age;
}

int
Pig_getLegCount() {
    return 4;
}

static AnimalVTable PigVTable = {
    .makeNoise = Pig_makeNoise,
    .getName = Pig_getName,
    .getAge = Pig_getAge,
    .getLegCount = Pig_getLegCount,
};

IAnimal 
pigInterface(Pig *self) {
    IAnimal interface;
    interface.ptr = self;
    interface.vtable = &PigVTable;

    return interface;
}

#endif