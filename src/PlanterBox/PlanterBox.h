#ifndef PLANTERBOX_H
#define PLANTERBOX_H

#include "../PlantableArea/PlantableArea.h"
#include "../Plant/Plant.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @class PlanterBox
 * @brief Leaf class representing a single planter box.
 * 
 * This class can hold multiple Plant objects and allows for operations
 * to be performed on the plants within the box.
 */

class Plant;
class PlanterBox : public PlantableArea {
private:

	/**
	 * @brief stores Plant objects in the PlanterBox
	 * Holds at most 5 plants
	 */
	std::vector<Plant*> plants;

	/**
	 * @brief maximum capacity of plants in the PlanterBox
	 */
	const int max_plant_capacity = 5;
public:

	/**
	 * @brief Default constructor for PlanterBox
	 */
	PlanterBox() = default;

	/**
	 * @brief Default destructor for PlanterBox
	 */
	~PlanterBox() = default;

	/**
	 * @brief Leaf method to add an area stubbed
	 */
	void add(PlantableArea* area) override;

	/**
	 * @brief Leaf method to remove an area stubbed
	 */
	void remove(PlantableArea* area) override;

	/**
	 * @brief Leaf method to get a child area stubbed
	 * 
	 * @param index index of the child to get
	 * 
	 * @return returns nullptr as PlanterBox is a leaf
	 */
	PlantableArea* getChild(int index) override;

	/**
	 * @brief Leaf method to display the PlanterBox details
	 */
    void display() override;

	/**
	 * @brief Leaf method to populate a plant in the PlanterBox
	 * 
	 * @param plant Plant object that needs to be added to PlanterBox object
	 */
	void populate(Plant* plant) override;

	/**
	 * @brief Leaf method to remove a Plant object from the PlanterBox
	 * 
	 * @param plant Plant object that needs to be removed
	 * 
	 * @return Returns the Plant Object that was removed so that it can be sold
	 */
	Plant* removePlant(Plant* plant) override;

	/**
	 * @brief Gets the plants in the PlanterBox
	 * 
	 * @return vector of Plant pointers in the PlanterBox
	 */
	const std::vector<Plant*> getPlants();

	/**
	 * @brief Waters plants at a certain index with a certain amount of units of water
	 * 
	 * @param units units of water to add
	 * @param index index of plant at which to add water to
	 */
	void water(int units, int index) override;

	/**
	 * @brief Gives plants medicine at a certain index with a certain amount of units of water
	 * 
	 * @param units units of medicine to give
	 * @param index index of plant at which to give medicine to
	 */
	void giveMedicine(int units, int index) override;

	/**
	 * @brief Fertilizes plants at a certain index with a certain amount of units of water
	 * 
	 * @param units units of fertilizer to add
	 * @param index index of plant at which to add fertilizer to
	 */
	void giveFertilizer(int units, int index) override;
};

#endif
