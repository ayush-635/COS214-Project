#ifndef PLANTERBOXCOLLECTION_H
#define PLANTERBOXCOLLECTION_H

#include "PlantableArea.h"
#include <string>
#include <vector>
#include <iostream>

class PlanterBoxCollection : PlantableArea {
private:
	std::vector<PlantableArea*> boxes; // can store up to 4 PlanterBox objects
public:
	PlanterBoxCollection() = default;
	~PlanterBoxCollection() override = default;

	// Operations for adding areas/tiles
	void add(PlantableArea* area) override;
	void remove(PlantableArea* area) override;
	PlantableArea* getChild(int index) override;

	// Delegation to contained planter boxes
	void populate(Plant* plant) override;
	void populate(Plant* plant, int plantBoxIndex);

	Plant* removePlant(Plant* plant) override;
	Plant* removePlant(Plant* plant, int plantBoxIndex);

	// plant operations
	void water(int units) override;
	void giveMedicine(int units) override;
	void giveFertilizer(int units) override;
};

#endif // PLANTERBOXCOLLECTION_H
