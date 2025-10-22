#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

class PlantFactory {

private:
	std::map<std::string, Plant*> plantProtoypes;

public:
	virtual Plant* createPlant() = 0;

	void addPlantPrototype(std::string name, std::string idealSeason);

	PlantFactory();
};

#endif
