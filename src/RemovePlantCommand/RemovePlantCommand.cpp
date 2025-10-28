#include "RemovePlantCommand.h"
#include <iostream>

RemovePlantCommand::RemovePlantCommand(PlanterBoxCollection* collection, Plant* targetPlant, int boxIndex)
    : collection(collection), targetPlant(targetPlant), boxIndex(boxIndex) {}

void RemovePlantCommand::executeDuty() {
    if (!collection) {
       
        return;
    }

    
    collection->removePlant(targetPlant, boxIndex);

    
}
