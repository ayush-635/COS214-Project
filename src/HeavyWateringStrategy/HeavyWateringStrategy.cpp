#include "../src/HeavyWateringStrategy/HeavyWateringStrategy.h"


void HeavyWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(5);
}
