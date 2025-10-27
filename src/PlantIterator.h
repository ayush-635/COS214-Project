#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Iterator.h"
#include "Plant.h"
#include "PlanterBox.h"
#include "PlantableArea.h"
#include <vector>

class PlantIterator : Iterator {
protected:
	int curIndex;
	std::vector<PlantableArea*> boxes;
	
public:
	PlantIterator(const std::vector<Plant*>& plantsList);
	~PlantIterator() override = default;
	bool hasNext() override;
	Plant* next() override;
	Plant* first() override;
	Plant* currItem() override;
};

#endif
