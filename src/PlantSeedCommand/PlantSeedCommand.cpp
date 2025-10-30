#include "PlantSeedCommand.h"
#include "../src/Plant/Plant.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include <iostream>

PlantSeedCommand::PlantSeedCommand(PlanterBoxCollection* collection, Plant* seed, int index)
    : Duty(collection, index), seed(seed) {}

void PlantSeedCommand::executeDuty() {
    if (!collection) {
        std::cout << "No plant row assigned.\n";
        return;
    }

    if (!seed) {
        std::cout << "No seed provided for planting.\n";
        return;
    }
    
    collection->populate(seed, index);

    
}

