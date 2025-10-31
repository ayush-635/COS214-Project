#ifndef HERBFACTORY_H
#define HERBFACTORY_H

#include "../PlantFactory/PlantFactory.h"

class HerbFactory : public PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
