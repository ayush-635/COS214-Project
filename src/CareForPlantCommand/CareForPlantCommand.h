#ifndef CAREFORPLANTCOMMAND_H
#define CAREFORPLANTCOMMAND_H

class CareForPlantCommand : Duty {


public:
	virtual void executeDuty(PlantableArea* area) = 0;
};

#endif
