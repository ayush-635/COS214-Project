#ifndef PLANTDATAFACTORY_H
#define PLANTDATAFACTORY_H

#include "../PlantData/PlantData.h"
#include <map>
#include <memory>

/**
 * @class PlantDataFactory
 * @brief Factory for creating and accessing plant data configurations
 */
class PlantDataFactory {
private:
    static std::map<std::string, std::shared_ptr<PlantData>> plantDataMap; ///< Registry of plant data

public:
    /**
     * @brief Get plant data for a specific species
     * @param key The species name to look up
     * @return std::shared_ptr<PlantData> Shared pointer to plant data, or nullptr if not found
     */
    static std::shared_ptr<PlantData> getPlantData(const std::string& key);
    
    /**
     * @brief Initialize the factory with all plant species data
     */
    static void initializeFactory();
};

#endif
