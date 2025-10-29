#include "src/PlantFactory/PlantFactory.h"

#include "src/Plant/Plant.h"

PlantFactory::~PlantFactory() {
	for(auto& prototypePair : plantProtoypes) {
		delete prototypePair.second;
	}
}

#include <iostream>
void PlantFactory::addPlantPrototype(Plant* prototype) {
	if(plantProtoypes.find(prototype->getName()) == plantProtoypes.end()) {
		plantProtoypes.insert({prototype->getName(), prototype->clone()});
	}
}
