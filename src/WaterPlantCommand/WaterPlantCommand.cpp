#include "WaterPlantCommand.h"

WaterPlantCommand::WaterPlantCommand(PlanterBoxCollection* collection, int boxIndex, WateringStrategy* strategy)
    : collection(collection), boxIndex(boxIndex), wateringStrategy(strategy) {}

void WaterPlantCommand::executeDuty(PlantableArea* area) {
    if (!collection || !wateringStrategy) return;

	
       PlantableArea* box = collection->getChild(boxIndex);
    if (!box) {
        
        return;
    }

    wateringStrategy->waterPlant(box);
}
