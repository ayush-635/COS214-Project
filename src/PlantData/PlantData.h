/**
 * @file PlantData.h
 * @brief Header file for the PlantData class
 */

#ifndef PLANTDATA_H
#define PLANTDATA_H
#include <string>

/**
 * @class PlantData
 * @brief Contains data and characteristics for a plant species
 */
class PlantData {
private:
    std::string speciesName;                    /**< Name of the plant species */
    double basePrice;                           /**< Base price of the plant */
    int wateringNeed;                           /**< Watering needs of the plant */
    int fertilizerNeed;                         /**< Fertilizer needs of the plant */
    double growthRate;                          /**< Growth rate of the plant */
    bool outside;                               /**< Whether plant grows outside */
    bool lowLight;                              /**< Whether plant requires low light */
    bool lowWater;                              /**< Whether plant requires low water */
    bool brightColour;                          /**< Whether plant has bright colors */
    bool lowCare;                               /**< Whether plant requires low care */
    int waterNeededForNextState;                /**< Water needed for next growth state */
    int fertilizerNeededForNextState;           /**< Fertilizer needed for next growth state */
    int waterInterval;                          /**< Water interval requirement */
    int fertilizerInterval;                     /**< Fertilizer interval requirement */
    int waterDeathTime;                         /**< Time until death without water */
    int fertilizerDeathTime;                    /**< Time until death without fertilizer */

public:
    /**
     * @brief Constructor for PlantData
     * @param name Species name
     * @param waterForState Water needed for next state
     * @param fertilizerForState Fertilizer needed for next state
     * @param waterInt Water interval
     * @param fertilizerInt Fertilizer interval
     * @param waterDeath Water death time
     * @param fertilizerDeath Fertilizer death time
     */
    PlantData(const std::string& name, int waterForState, int fertilizerForState,
              int waterInt, int fertilizerInt, int waterDeath, int fertilizerDeath);
    
    /**
     * @brief Copy constructor
     * @param other PlantData to copy from
     */
    PlantData(const PlantData& other);

    /**
     * @brief Get species name
     * @return Species name
     */
    std::string getSpeciesName() const { return speciesName; }
    
    /**
     * @brief Get water needed for next state
     * @return Water needed for next state
     */
    int getWaterNeededForNextState() const { return waterNeededForNextState; }
    
    /**
     * @brief Get fertilizer needed for next state
     * @return Fertilizer needed for next state
     */
    int getFertilizerNeededForNextState() const { return fertilizerNeededForNextState; }
    
    /**
     * @brief Get water interval
     * @return Water interval
     */
    int getWaterInterval() const { return waterInterval; }
    
    /**
     * @brief Get fertilizer interval
     * @return Fertilizer interval
     */
    int getFertilizerInterval() const { return fertilizerInterval; }
    
    /**
     * @brief Get water death time
     * @return Water death time
     */
    int getWaterDeathTime() const { return waterDeathTime; }
    
    /**
     * @brief Get fertilizer death time
     * @return Fertilizer death time
     */
    int getFertilizerDeathTime() const { return fertilizerDeathTime; }
    
    /**
     * @brief Check if plant is for outside
     * @return True if plant is for outside
     */
    bool isOutside() const { return outside; }
    
    /**
     * @brief Check if plant requires low light
     * @return True if plant requires low light
     */
    bool isLowLight() const { return lowLight; }
    
    /**
     * @brief Check if plant requires low water
     * @return True if plant requires low water
     */
    bool isLowWater() const { return lowWater; }
    
    /**
     * @brief Check if plant has bright colors
     * @return True if plant has bright colors
     */
    bool isBrightColour() const { return brightColour; }
    
    /**
     * @brief Check if plant requires low care
     * @return True if plant requires low care
     */
    bool isLowCare() const { return lowCare; }
    
    /**
     * @brief Get plant data pointer
     * @return Pointer to plant data
     */
    PlantData* getPlantData(){return this;};
};

#endif