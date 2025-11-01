
#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "../Iterator/Iterator.h"
#include "../Plant/Plant.h"
#include "../PlanterBox/PlanterBox.h"
#include "../PlantableArea/PlantableArea.h"
#include "../PlanterBoxCollection/PlanterBoxCollection.h"
#include <vector>
#include <iostream>
#include <cstddef>
#include <string>
#include <stack>

class PlantIterator : public Iterator {
protected:
	size_t plantIndex;
	PlantableArea* rootArea; // first box in collection
	std::stack<PlantableArea*> areaStack; // stack to manage nested areas
	std::vector<Plant*> plants; // plants in current box
	
	void loadCurrentBoxPlants();
    void advanceToNextValidBox();

public:
	PlantIterator(PlantableArea* baseArea);
	~PlantIterator();

	bool hasNext() override;
	Plant* next() override;
	Plant* first() override;
	Plant* currItem() override;
};

#endif // PLANTITERATOR_H