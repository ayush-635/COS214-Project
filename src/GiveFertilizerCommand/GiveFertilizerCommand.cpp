#include "GiveFertilizerCommand.h"
#include <iostream>

GiveFertilizerCommand::GiveFertilizerCommand(PlanterBoxCollection* collection, int boxIndex, int units)
    : collection(collection), boxIndex(boxIndex), units(units) {}

void GiveFertilizerCommand::executeDuty() {
    if (!collection) return;

    collection->giveFertilizer(units, boxIndex); 
}
