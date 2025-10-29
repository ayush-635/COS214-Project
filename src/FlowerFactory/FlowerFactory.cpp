#include "src/FlowerFactory/FlowerFactory.h"

#include "src/Plant/Plant.h"

Plant* FlowerFactory::createPlant(std::string name) {
	auto plantPos = getPlantPrototypes().find(name);
	if(plantPos == getPlantPrototypes().end()) {
		return nullptr;
	} else {
		return getPlantPrototypes().find(name)->second->clone();
	}
}
