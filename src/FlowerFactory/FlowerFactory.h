#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class FlowerFactory : PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
