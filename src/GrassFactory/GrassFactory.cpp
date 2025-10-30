#include "src/GrassFactory/GrassFactory.h"

#include "src/Plant/Plant.h"

Plant* GrassFactory::createPlant(std::string name) {
	auto plantPos = getPlantPrototypes().find(name);
	if(plantPos == getPlantPrototypes().end()) {
		return nullptr;
	} else {
		return getPlantPrototypes().find(name)->second->clone();
	}
}
