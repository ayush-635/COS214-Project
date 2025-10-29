#include "src/PlantFactory/PlantFactory.h"

#include "src/Plant/Plant.h"

void PlantFactory::addPlantPrototype(Plant* prototype) {
	if(plantProtoypes.find(prototype->getName()) == plantProtoypes.end()) {
		plantProtoypes.insert({prototype->getName(), prototype->clone()});
	}
}
