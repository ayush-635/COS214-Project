#ifndef HERBFACTORY_H
#define HERBFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class HerbFactory : PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
