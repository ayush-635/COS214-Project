#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <string>
#include <map>

class Plant;


/** 
 * @class PlantFactory
 * @brief Factory for creating Plant objects.
 * 
 * Maintains a std::map with plant prototypes identified by their names.
 * It provides methods to add prototypes to the prototype map and create new Plant instances by cloning these prototypes.
 * Serves as a base class for specific plant factories.
 */
class PlantFactory {
private:
	std::map<std::string, Plant*> plantProtoypes; /// Prototype map

public:
	/* 
	 * @brief Destructor freeing stored prototypes in the prototype map.
	 */
	virtual ~PlantFactory();

	/*
	 * @brief Adds a plant prototype to the prototypes map.
     *
	 * @param prototype Pointer to the Plant prototype to be added.
	 * 
	 * @note A deep copy of the passed in prototype is stored in the prototype map.
	 */
	virtual void addPlantPrototype(Plant* prototype);

	/*
	 * @brief Returns the plant prototypes map.
	 * 
	 * @return Reference to the map of plant prototypes.
	 */
	std::map<std::string, Plant*>& getPlantPrototypes() {
		return plantProtoypes;
	}
	
	/*
	 * @brief Creates a new Plant instance by cloning the prototype associated with the given name.
	 * 
	 * @param name The name of the plant prototype to clone.
	 * 
	 * @return Pointer to the newly created Plant instance.
	 * 
	 * @note This is a pure virtual function that must be implemented by derived classes.
	 */
	virtual Plant* createPlant(std::string name) = 0;
};

#endif
