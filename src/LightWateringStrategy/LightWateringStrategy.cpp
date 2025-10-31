#include "LightWateringStrategy.h"
#include "../src/PlantableArea/PlantableArea.h"
#include "../src/PlanterBox/PlanterBox.h"


void LightWateringStrategy::waterPlant(PlantableArea* area) {
	 if (!area) return;
	 
	 area->water(1,0);
}
