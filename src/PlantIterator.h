#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Iterator.h"
#include "Plant.h"
#include "PlanterBox.h"
#include "PlantableArea.h"
#include <vector>

class PlantIterator : Iterator {
protected:
	size_t boxIndex;
	size_t plantIndex;
	std::vector<PlantableArea*> boxes; // planter boxes in collection
	std::vector<Plant*> plants; // plants in current box
	
	void loadCurrentBoxPlants();
    void advanceToNextValidBox();

public:
	PlantIterator(const std::vector<PlantableArea*>& plantsList);
	~PlantIterator() override = default;

	bool hasNext() override;
	Plant* next() override;
	Plant* first() override;
	Plant* currItem() override;
};

#endif
