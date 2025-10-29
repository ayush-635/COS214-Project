#ifndef GRASSFACTORY_H
#define GRASSFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class GrassFactory : PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
