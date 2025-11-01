#ifndef HERBFACTORY_H
#define HERBFACTORY_H

#include "../PlantFactory/PlantFactory.h"

class HerbFactory : public PlantFactory {
public:

	/*
	 * @brief Creates a new herb plant instance by cloning the prototype associated with the given name.
	 * 
	 * @param name The name of the herb plant prototype to clone.
	 * 
	 * @return Pointer to the newly created herb plant instance.
	 * 
	 * @note Implements the createPlant method from the PlantFactory base class.
	 */
	virtual Plant* createPlant(std::string name) override;
};

#endif
