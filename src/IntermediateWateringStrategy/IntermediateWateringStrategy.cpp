#include "../src/IntermediateWateringStrategy/IntermediateWateringStrategy.h"


void IntermediateWateringStrategy::waterPlant(PlantableArea* area) {
    if (!area) return;
	
	area->water(3);
}