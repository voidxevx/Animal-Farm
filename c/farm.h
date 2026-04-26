#ifndef FARM_H
#define FARM_H

#include <stdio.h>
#include "animal.h"

typedef struct
Farm {
    IAnimal *animals;
    int animal_count;
} Farm;

void addAnimal(Farm *farm, IAnimal animal) {
    farm->animals[farm->animal_count] = animal;
    farm->animal_count++;
}

void surveyFarm(Farm *farm) {
    printf("Animals:\n");
    for (unsigned int i = 0; i < farm->animal_count; i++) {
        IAnimal animal = farm->animals[i];
        printf("\t%s, age: %i, legs: %i\n", getName(animal), getAge(animal), getLegCount(animal));
    }
}

#endif