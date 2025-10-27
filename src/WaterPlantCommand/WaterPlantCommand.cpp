#include "WaterPlantCommand.h"

WaterPlantCommand::WaterPlantCommand(WateringStrategy* strategy)
    : wateringStrategy(strategy) {}

void WaterPlantCommand::executeDuty(PlantableArea* area) {
    if (!area && !wateringStrategy) return;

	
        wateringStrategy->waterPlant(area);
}
