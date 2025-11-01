#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H

#include "../PlantFactory/PlantFactory.h"

class FlowerFactory : public PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
