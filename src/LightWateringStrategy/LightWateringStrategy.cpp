#include "../src/LightWateringStrategy/LightWateringStrategy.h"


void LightWateringStrategy::waterPlant(PlantableArea* area) {
	 if (!area) return;
	 
	 area->water(1);
}
