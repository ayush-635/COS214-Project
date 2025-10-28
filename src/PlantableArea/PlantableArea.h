#ifndef PLANTABLEAREA_H
#define PLANTABLEAREA_H

class PlantableArea {

private:
	Duty receiver;

public:
	virtual void populate(Plant* plant) = 0;

	virtual Plant* removePlant(Plant* plant) = 0;

	virtual void water(int units) = 0;

	virtual void giveMedicine() = 0;

	virtual void giveFertilizer(int units) = 0;
};

#endif
