#ifndef CHICKEN_ANIMAL_H
#define CHICKEN_ANIMAL_H

#include <stdio.h>
#include "animal.h"

typedef struct
Chicken {
    const char *name;
    int age;
} Chicken;

void 
Chicken_makeNoise() {
    printf("Cluck!");
}

const char
*Chicken_getName(void *ptr) {
    Chicken *self = (Chicken*)ptr;
    return self->name;
}

int
Chicken_getAge(void *ptr) {
    Chicken *self = (Chicken*)ptr;
    return self->age;
}

int
Chicken_getLegCount() {
    return 2;
}

static AnimalVTable ChickenVTable = {
    .makeNoise = Chicken_makeNoise,
    .getName = Chicken_getName,
    .getAge = Chicken_getAge,
    .getLegCount = Chicken_getLegCount,
};

IAnimal
chickenInterface(Chicken *self) {
    IAnimal interface;
    interface.ptr = self;
    interface.vtable = &ChickenVTable;

    return interface;
}

#endif