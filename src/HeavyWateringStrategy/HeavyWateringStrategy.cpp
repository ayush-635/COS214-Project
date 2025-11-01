#include "HeavyWateringStrategy.h"
#include "../PlantableArea/PlantableArea.h"
#include "../PlanterBox/PlanterBox.h"



void HeavyWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(5,0);
}
