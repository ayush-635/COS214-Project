#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H

#include "../PlantFactory/PlantFactory.h"

class FlowerFactory : public PlantFactory {
public:

	/*
	 * @brief Creates a new flower plant instance by cloning the prototype associated with the given name.
	 * 
	 * @param name The name of the flower plant prototype to clone.
	 * 
	 * @return Pointer to the newly created flower plant instance.
	 * 
	 * @note Implements the createPlant method from the PlantFactory base class.
	 */
	virtual Plant* createPlant(std::string name) override;
};

#endif
