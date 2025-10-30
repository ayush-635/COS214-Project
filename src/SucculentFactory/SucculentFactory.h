#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class Plant;

class SucculentFactory : public PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
