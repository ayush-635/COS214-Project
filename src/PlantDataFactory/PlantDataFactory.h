#ifndef PLANTDATAFACTORY_H
#define PLANTDATAFACTORY_H

#include "src/PlantData/PlantData.h"
#include <map>
#include <memory>

class PlantDataFactory {
private:
    static std::map<std::string, std::shared_ptr<PlantData>> plantDataMap;

public:
    static std::shared_ptr<PlantData> getPlantData(const std::string& key);
    static void initializeFactory();
};

#endif