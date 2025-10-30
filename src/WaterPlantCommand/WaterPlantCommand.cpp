#include "WaterPlantCommand.h"

WaterPlantCommand::WaterPlantCommand(PlanterBoxCollection* collection, WateringStrategy* strategy, int index)
    : collection(collection), index(index), wateringStrategy(strategy) {}

void WaterPlantCommand::executeDuty() {
    if (!collection || !wateringStrategy) return;

	
       PlantableArea* box = collection->getChild(index);
    if (!box) {
        
    std::cout << "Invalid box index: " << index << "\n";
    
    return;

    }

    wateringStrategy->waterPlant(box);
}
