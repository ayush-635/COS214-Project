#include "PlantSeedCommand.h"


PlantSeedCommand::PlantSeedCommand(PlanterBoxCollection* collection, Plant* seed, int boxIndex)
    : collection(collection), seed(seed), boxIndex(boxIndex) {}

void PlantSeedCommand::executeDuty() {
    if (!collection || !seed) {
       
        return;
    }

    
    collection->populate(seed, boxIndex);

    
}

