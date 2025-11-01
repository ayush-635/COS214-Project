#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class TreeFactory : PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
