
#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "src/Iterator/Iterator.h"
#include "src/Plant/Plant.h"
#include "src/PlanterBox/PlanterBox.h"
#include "src/PlantableArea/PlantableArea.h"
#include <vector>
#include <iostream>
#include <cstddef>
#include <string>

class PlantIterator : public Iterator {
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

#endif // PLANTITERATOR_H