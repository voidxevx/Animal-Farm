#include "farm.h"
#include "pig.h"
#include "chicken.h"
#include <stdlib.h>

int main() {
    Pig cesar;
    cesar.name = "Cesar";
    cesar.age = 45;

    Chicken cluck;
    cluck.name = "Mother-Clucker";
    cluck.age = 2;

    Farm farm;
    farm.animal_count = 0;
    farm.animals = malloc(16 * sizeof(IAnimal));

    addAnimal(&farm, pigInterface(&cesar));
    addAnimal(&farm, chickenInterface(&cluck));

    surveyFarm(&farm);

    return 0;
}