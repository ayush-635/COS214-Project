#include "HeavyWateringStrategy.h"
#include "../src/PlantableArea/PlantableArea.h"
#include "../src/PlanterBox/PlanterBox.h"



void HeavyWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(5);
}
