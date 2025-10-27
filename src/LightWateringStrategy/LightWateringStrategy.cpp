#include "LightWateringStrategy.h"
#include "PlantableArea.h"

void LightWateringStrategy::waterPlant(PlantableArea* area) {
	 if (!area) return;
	 
	 area->water(1);
}
