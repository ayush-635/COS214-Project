#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H

class WaterPlantCommand : CareForPlantCommand {

public:
	WateringStrategy* wateringStrategy;

	void executeDuty(PlantableArea* area);
};

#endif
