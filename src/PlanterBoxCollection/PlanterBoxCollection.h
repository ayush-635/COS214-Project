#ifndef PLANTERBOXCOLLECTION_H
#define PLANTERBOXCOLLECTION_H

#include "../PlantableArea/PlantableArea.h"
#include <string>
#include <vector>
#include <iostream>

class PlanterBoxCollection : public PlantableArea {
private:
	std::vector<PlantableArea*> boxes; // can store up to 4 PlanterBox objects
	int depth;
	int max_depth = 1; // only 1 level of nesting allowed
	int max_boxes = 4; // max 4 planter boxes in collection
	
public:
	PlanterBoxCollection(int depth);
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
	void water(int units, int index) override;
	void giveMedicine(int units, int index) override;
	void giveFertilizer(int units, int index) override;

	void display() override;
	int getDepth() const;
};

#endif // PLANTERBOXCOLLECTION_H