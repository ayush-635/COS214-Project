#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <string>
#include <map>

class Plant;

class PlantFactory {
private:
	std::map<std::string, Plant*> plantProtoypes;

public:
	virtual ~PlantFactory();

	virtual void addPlantPrototype(Plant* prototype);

	std::map<std::string, Plant*>& getPlantPrototypes() {
		return plantProtoypes;
	}

	virtual Plant* createPlant(std::string name) = 0;
};

#endif
