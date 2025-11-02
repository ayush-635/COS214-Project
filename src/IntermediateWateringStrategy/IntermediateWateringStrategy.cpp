#include "IntermediateWateringStrategy.h"
#include "../PlantableArea/PlantableArea.h"
#include "../PlanterBox/PlanterBox.h"



void IntermediateWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(3,0);
}