#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class Plant;

class SucculentFactory : public PlantFactory {
public:	

	/*
	 * @brief Creates a new succulent plant instance by cloning the prototype associated with the given name.
	 * 
	 * @param name The name of the succulent plant prototype to clone.
	 * 
	 * @return Pointer to the newly created succulent plant instance.
	 * 
	 * @note Implements the createPlant method from the PlantFactory base class.
	*/
	virtual Plant* createPlant(std::string name) override;
};

#endif
