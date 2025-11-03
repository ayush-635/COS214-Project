/**
 * @file PlantDataFactory.h
 * @brief Header file for the PlantDataFactory class
 */

#ifndef PLANTDATAFACTORY_H
#define PLANTDATAFACTORY_H

#include "../PlantData/PlantData.h"
#include <map>
#include <memory>

/**
 * @class PlantDataFactory
 * @brief Factory class for creating and managing plant data
 */
class PlantDataFactory {
private:
    static std::map<std::string, std::shared_ptr<PlantData>> plantDataMap; /**< Static map of plant data */

public:
    /**
     * @brief Get plant data for a specific key
     * @param key Key identifying the plant data
     * @return Shared pointer to plant data
     */
    static std::shared_ptr<PlantData> getPlantData(const std::string& key);
    
    /**
     * @brief Initialize the factory with plant data
     */
    static void initializeFactory();
};

#endif