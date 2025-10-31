#include "PlantDataFactory.h"
#include <iostream>

std::map<std::string, std::shared_ptr<PlantData>> PlantDataFactory::plantDataMap;

std::shared_ptr<PlantData> PlantDataFactory::getPlantData(const std::string& key) {
    auto it = plantDataMap.find(key);
    if (it != plantDataMap.end()) {
        return it->second;
    }
    return nullptr;
}


//PlantData(const std::string& name, int waterForState, int fertilizerForState, 
//          int waterInt, int fertilizerInt, int waterDeath, int fertilizerDeath)

void PlantDataFactory::initializeFactory() {
    plantDataMap["FlowerPlant"] = std::make_shared<PlantData>("FlowerPlant", 5, 3, 5, 8, 10, 15);
    plantDataMap["TreePlant"] = std::make_shared<PlantData>("TreePlant", 3, 2, 10, 12, 20, 25);
    plantDataMap["HerbPlant"] = std::make_shared<PlantData>("HerbPlant", 4, 2, 4, 6, 8, 12);
    plantDataMap["GrassPlant"] = std::make_shared<PlantData>("GrassPlant", 2, 1, 3, 5, 6, 10);
    plantDataMap["SucculentPlant"] = std::make_shared<PlantData>("SucculentPlant", 2, 1, 15, 20, 30, 40);
    
    std::cout << "PlantDataFactory initialized with " << plantDataMap.size() << " plant types.\n";
}