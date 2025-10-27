#ifndef PLANTABLEAREA_H
#define PLANTABLEAREA_H

#include "Duty.h"
#include "Plant.h"


class PlantableArea {
private:
	Duty* receiver;

public:
	virtual ~PlantableArea() = default;

	virtual void populate(Plant* plant) = 0;
	virtual Plant* removePlant(Plant* plant) = 0;

	virtual void water(int units) = 0;
	virtual void giveMedicine(int units) = 0;
	virtual void giveFertilizer(int units) = 0;

	virtual void add(PlantableArea* area);
	virtual void remove(PlantableArea* area);
	virtual PlantableArea* getChild(int index);
};

#endif
