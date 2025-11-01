#include "RemovePlantCommand.h"
#include "../Plant/Plant.h"
#include "../PlanterBoxCollection/PlanterBoxCollection.h"
#include <iostream>


RemovePlantCommand::RemovePlantCommand(PlanterBoxCollection* collection, Plant* targetPlant, int index)
    : Duty(collection, index), targetPlant(targetPlant) {}

void RemovePlantCommand::executeDuty() {
   
    if (!collection) {
        std::cout << " No plant row assigned.\n";
        return;
    }

    if (!targetPlant) {
        std::cout << "Not given a plant to remove.\n";
        return;
    }

    collection->removePlant(targetPlant, index);
    
}
