#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class TreeFactory : PlantFactory {
public:

	/*
	 * @brief Creates a new tree plant instance by cloning the prototype associated with the given name.
	 * 
	 * @param name The name of the tree plant prototype to clone.
	 * 
	 * @return Pointer to the newly created tree plant instance.
	 * 
	 * @note Implements the createPlant method from the PlantFactory base class.
	 */
	virtual Plant* createPlant(std::string name) override;
};

#endif
