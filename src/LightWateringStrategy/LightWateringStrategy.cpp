#include "LightWateringStrategy.h"
#include "../PlantableArea/PlantableArea.h"
#include "../PlanterBox/PlanterBox.h"


void LightWateringStrategy::waterPlant(PlantableArea* area) {
	 if (!area) return;
	 
	 area->water(1,0);
}
