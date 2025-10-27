#include "GiveFertilizerCommand.h"


GiveFertilizerCommand::GiveFertilizerCommand(int units) : units(units) {}

void GiveFertilizerCommand::executeDuty(PlantableArea* area) {
	
	if (!area) return;
	
	area->giveFertilizer(units);
}
