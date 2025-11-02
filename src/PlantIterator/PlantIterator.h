/**
 * @file PlantIterator.h
 * @author ryan Lynn
 * @brief Header file for the PlantIterator class
 */
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

/**
 * @class PlantIterator
 * @brief Iterator for traversing through plants in plantable areas and boxes
 */
class PlantIterator : public Iterator {
protected:
	/**
	 * @brief index of the current plant in the plants vector
	 */
	size_t plantIndex;

	/**
	 * @brief root PlantableArea to start iteration from
	 */
	PlantableArea* rootArea;

	/**
	 * @brief stack to manage nested PlantableArea objects during iteration
	 */
	std::stack<PlantableArea*> areaStack;

	/**
	 * @brief vector to hold plants in the current PlanterBox being iterated over
	 */
	std::vector<Plant*> plants;
	
	/**
	 * @brief loads plants from the current PlanterBox at the top of the stack
	 */
	void loadCurrentBoxPlants();

	/**
	 * @brief advances the iterator to the next valid PlanterBox with plants
	 */
    void advanceToNextValidBox();

public:

	/**
	 * @brief Constructor for PlantIterator
	 * 
	 * @param baseArea Root PlantableArea to start iteration from
	 */
	PlantIterator(PlantableArea* baseArea);

	/**
	 * @brief Destructor for PlantIterator
	 */
	~PlantIterator();

	/**
	 * @brief Checks if there are more collections or boxes to iterate over
	 */
	bool hasNext() override;

	/**
	 * @brief Returns the next box or collection in the iteration
	 */
	Plant* next() override;

	/**
	 * @brief Returns the first box or collection in the iteration
	 */
	Plant* first() override;

	/**
	 * @brief Returns the current box or collection in the iteration
	 */
	Plant* currItem() override;
};

#endif // PLANTITERATOR_H