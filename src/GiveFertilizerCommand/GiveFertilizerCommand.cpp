#include "GiveFertilizerCommand.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include <iostream>



GiveFertilizerCommand::GiveFertilizerCommand(PlanterBoxCollection* collection, int units, int index)
    : CareForPlantCommand(collection, index), units(units) {}



void GiveFertilizerCommand::executeDuty() {

     if (!collection) {
        std::cout << " No plant row assigned.\n";
        return;
    }

    collection->giveFertilizer(units, index); 
}
