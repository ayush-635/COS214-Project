#ifndef PLANTABLEAREA_H
#define PLANTABLEAREA_H
#include <vector>

/**
 * @class PlantableArea
 * @brief Abstract base class representing a plantable area in the game.
 * 
 * The PlantArea class stores a reciever which tells it what duty it must perform on a plant, such as when to water, fertilize, or
 * give it medicine.
 * 
 * It also stores a list of children of the component which can be a leaf or a composite
 */
class Plant;
class Duty;

class PlantableArea {
private:
	/**
	 * @brief recieves an instruction on which action to perform 
	 */
	Duty* receiver;

	/**
	 * @brief stores children objects of the component which could be leaves or composites
	 */
	std::vector<PlantableArea*> children;
public:

	/**
	 * @brief Virtual default destructor for the PlantAreaObject
	 */
	virtual ~PlantableArea() = default;

	/**
	 * @brief Function to add a Plant object
	 * 
	 * In leaf adds plant to the first available spot in PlanterBox object if PlanterBox object is not full.
	 * In composite adds PlanterBox object into collection if it is not full.
	 * 
	 * @param plant Plant object that needs to be added to PlanterBox object
	 */
	virtual void populate(Plant* plant) = 0;

	/**
	 * @brief Removes a Plant Object
	 * 
	 * In leaf it removes a Plant object with a matching pointer
	 * In composite removes a PlanterBox
	 * 
	 * @param plant Plant object that needs to be removed
	 * 
	 * @return Returns the Plant Object that was removed so that it can be sold
	 */
	virtual Plant* removePlant(Plant* plant) = 0;

	/**
	 * @brief Waters plants at a certain index with a certain amount of units of water
	 * 
	 * @param units units of water to add
	 * @param index index of plant at which to add water to
	 */
	virtual void water(int units, int index) = 0;

	/**
	 * @brief Gives plants medicine at a certain index with a certain amount of units of water
	 * 
	 * @param units units of medicine to give
	 * @param index index of plant at which to give medicine to
	 */
	virtual void giveMedicine(int units, int index) = 0;

	/**
	 * @brief Fertilizes plants at a certain index with a certain amount of units of water
	 * 
	 * @param units units of fertilizer to add
	 * @param index index of plant at which to add fertilizer to
	 */
	virtual void giveFertilizer(int units, int index) = 0;

	/**
	 * @brief adds a PlantableArea object to the collection
	 * 
	 * @param area PlantableArea object to add
	 */
	virtual void add(PlantableArea* area) = 0;

	/**
	 * @brief removes a PlantableArea object from the collection
	 * 
	 * @param area PlantableArea object to remove
	 */
	virtual void remove(PlantableArea* area) = 0;

	/**
	 * @brief gets a child PlantableArea object from the collection at a certain index
	 * 
	 * @param index index of the child to get
	 * 
	 * @return returns the PlantableArea object at the index
	 */
	virtual PlantableArea* getChild(int index) = 0;

	/**
	 * @brief displays the PlantableArea object details
	 */
	virtual void display() = 0;
};

#endif // PLANTABLEAREA_H
