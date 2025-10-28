#ifndef PLANTDATAFACTORY_H
#define PLANTDATAFACTORY_H

class PlantDataFactory {

private:
	map<string, PlantData*> plantDataMap;

public:
	PlantData* getPlantData(string key);

	PlantDataFactory();
};

#endif
