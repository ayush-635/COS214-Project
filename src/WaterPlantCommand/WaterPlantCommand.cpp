#include "WaterPlantCommand.h"
#include "../src/WateringStrategy/WateringStrategy.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include "../src/PlantableArea/PlantableArea.h"
#include <iostream>



WaterPlantCommand::WaterPlantCommand(PlanterBoxCollection* collection, WateringStrategy* strategy, int index)
    : CareForPlantCommand(collection, index), wateringStrategy(strategy) {}

void WaterPlantCommand::executeDuty() {
    if (!collection || !wateringStrategy) return;

	
       PlantableArea* box = collection->getChild(index);
    if (!box) {
        
    std::cout << "Invalid box index: " << index << "\n";
    
    return;

    }

    wateringStrategy->waterPlant(box);
}
