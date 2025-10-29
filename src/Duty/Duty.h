#ifndef DUTY_H
#define DUTY_H

class PlantableArea;

class Duty {


public:
	virtual void executeDuty(PlantableArea* area) = 0;

	Duty();
};

#endif
