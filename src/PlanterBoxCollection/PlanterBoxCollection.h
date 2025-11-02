#ifndef PLANTERBOXCOLLECTION_H
#define PLANTERBOXCOLLECTION_H

#include "../PlantableArea/PlantableArea.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @class PlanterBoxCollection
 * @brief Composite class representing a collection of planter boxes.
 * 
 * This class can contain multiple PlanterBox objects and allows for operations
 * to be performed on the collection as a whole or delegated to individual boxes.
 * 
 * Stores a depth variable to see nesting of the composites in the collections
 * Stores a maximum depth and maximum number of boxes allowed
 */

class PlanterBoxCollection : public PlantableArea {
private:

	/**
	 * @brief stores PlanterBox objects in the collection can be up to 4 boxes a collection
	 */
	std::vector<PlantableArea*> boxes; 

	/**
	 * @brief depth of the current collection in the overall structure
	 */
	int depth;

	/**
	 * @brief maximum allowed depth for nesting collections(only allowed 1 level of nesting)
	 */
	int max_depth = 1; 

	/**
	 * @brief maximum number of planter boxes allowed in the collection(up to 4 boxes allowed to be stored in collection)
	 */
	int max_boxes = 4;
	
public:
	/**
	 * @brief Constructor for PlanterBoxCollection
	 * 
	 * @param depth Depth of the collection in the overall structure
	 */
	PlanterBoxCollection(int depth);

	/**
	 * @brief Destructor for PlanterBoxCollection
	 */
	~PlanterBoxCollection() override = default;

	/**
	 * @brief Composite methods to manage PlanterBox objects in the collection
	 * 
	 * @param area PlantableArea object to add
	 */
	void add(PlantableArea* area) override;

	/**
	 * @brief Composite method to remove a PlanterBox from the collection
	 * 
	 * @param area PlantableArea object to remove
	 */
	void remove(PlantableArea* area) override;

	/**
	 * @brief Composite method to get a child PlanterBox from the collection at a certain index
	 * 
	 * @param index index of the child to get
	 * 
	 * @return returns the PlantableArea object at the index
	 */
	PlantableArea* getChild(int index) override;

	/**
	 * @brief Composite methoto populate a plant in the first available PlanterBox
	 * 
	 * @param plant Plant object that needs to be added to PlanterBox object
	 */
	void populate(Plant* plant) override;

	/**
	 * @brief Composite method to populate a plant in a specific PlanterBox by index
	 * 
	 * @param plant Plant object that needs to be added to PlanterBox object
	 * @param plantBoxIndex index of the PlanterBox in the collection to add the plant to
	 */
	void populate(Plant* plant, int plantBoxIndex);

	/**
	 * @brief Composite method to remove a Plant object from the collection
	 * 
	 * @param plant Plant object that needs to be removed
	 * 
	 * @return Returns the Plant Object that was removed so that it can be sold
	 */
	Plant* removePlant(Plant* plant) override;

	/**
	 * @brief Composite method to remove a Plant object from a specific PlanterBox by index
	 * 
	 * @param plant Plant object that needs to be removed
	 * @param plantBoxIndex index of the PlanterBox in the collection to remove the plant from
	 * 
	 * @return Returns the Plant Object that was removed so that it can be sold
	 */
	Plant* removePlant(Plant* plant, int plantBoxIndex);

	/**
	 * @brief Composite car method for watering plants in a specific PlanterBox by index
	 * 
	 * @param units units of water to add
	 * @param index index of plant at which to add water to
	 */
	void water(int units, int index) override;

	/**
	 * @brief Composite care method for giving medicine to plants in a specific PlanterBox by index
	 * 
	 * @param units units of medicine to give
	 * @param index index of plant at which to give medicine to
	 */
	void giveMedicine(int units, int index) override;

	/**
	 * @brief Composite care method for fertilizing plants in a specific PlanterBox by index
	 * 
	 * @param units units of fertilizer to add
	 * @param index index of plant at which to add fertilizer to
	 */
	void giveFertilizer(int units, int index) override;

	/**
	 * @brief Displays the PlanterBoxCollection details
	 */
	void display() override;

	/**
	 * @brief Gets the depth of the current collection
	 * 
	 * @return depth of the collection
	 */
	int getDepth() const;
};

#endif // PLANTERBOXCOLLECTION_H