#include "IntermediateWateringStrategy.h"
#include "PlantableArea.h"

void IntermediateWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(3);
}