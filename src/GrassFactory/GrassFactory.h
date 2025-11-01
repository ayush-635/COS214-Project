#ifndef GRASSFACTORY_H
#define GRASSFACTORY_H

#include "../PlantFactory/PlantFactory.h"

class GrassFactory : public PlantFactory {
public:

	/*
	 * @brief Creates a new grass plant instance by cloning the prototype associated with the given name.
	 * 
	 * @param name The name of the grass plant prototype to clone.
	 * 
	 * @return Pointer to the newly created grass plant instance.
	 * 
	 * @note Implements the createPlant method from the PlantFactory base class.
	 */
	virtual Plant* createPlant(std::string name) override;
};

#endif
