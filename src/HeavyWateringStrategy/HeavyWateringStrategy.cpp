#include "HeavyWateringStrategy.h"
#include "PlantableArea.h"

void HeavyWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(5);
}
