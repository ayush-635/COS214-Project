#ifndef GRASSFACTORY_H
#define GRASSFACTORY_H

#include "../PlantFactory/PlantFactory.h"

class GrassFactory : public PlantFactory {
public:
	virtual Plant* createPlant(std::string name) override;
};

#endif
