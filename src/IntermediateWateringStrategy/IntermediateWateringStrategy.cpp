#include "IntermediateWateringStrategy.h"
#include "../src/PlantableArea/PlantableArea.h"
#include "../src/PlanterBox/PlanterBox.h"



void IntermediateWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(3);
}