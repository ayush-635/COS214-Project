#ifndef PLANTERBOX_H
#define PLANTERBOX_H

#include "PlantableArea.h"
#include <string>
#include <vector>
#include <iostream>

class PlanterBox : public PlantableArea {
private:
	std::vector<Plant*> plants; // holds at most 5 plants
	const int max_plant_capacity = 5;
public:
	PlanterBox() = default;
	~PlanterBox() = default;

	void add(PlantableArea* area) override;
	void remove(PlantableArea* area) override;
	PlantableArea* getChild(int index) override;
    void display() override;

	void populate(Plant* plant) override;
	Plant* removePlant(Plant* plant) override;
	const std::vector<Plant*> getPlants();

	void water(int units) override;
	void giveMedicine(int units) override;
	void giveFertilizer(int units) override;
};

#endif
