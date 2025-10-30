#ifndef PLANTABLEAREA_H
#define PLANTABLEAREA_H

#include "src/Duty/Duty.h"
#include "src/Plant/Plant.h"
#include <vector>

class PlantableArea {
private:
	Duty* receiver;
	std::vector<PlantableArea*> children;
public:
	virtual ~PlantableArea() = default;

	virtual void populate(Plant* plant) = 0;
	virtual Plant* removePlant(Plant* plant) = 0;

	virtual void water(int units) = 0;
	virtual void giveMedicine(int units) = 0;
	virtual void giveFertilizer(int units) = 0;

	virtual void add(PlantableArea* area) = 0;
	virtual void remove(PlantableArea* area) = 0;
	virtual PlantableArea* getChild(int index) = 0;
	virtual void display() = 0;
};

#endif // PLANTABLEAREA_H
