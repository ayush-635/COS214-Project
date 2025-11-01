#ifndef PLANTDATA_H
#define PLANTDATA_H
#include <string>

/**
 * @class PlantData
 * @brief Configuration data container for plant species
 */
class PlantData {
private:
    std::string speciesName;
    double basePrice;
    int wateringNeed;
    int fertilizerNeed;
    double growthRate;
    bool outside;
    bool lowLight;
    bool lowWater;
    bool brightColour;
    bool lowCare;
    int waterNeededForNextState;
    int fertilizerNeededForNextState;
    int waterInterval;
    int fertilizerInterval;
    int waterDeathTime;
    int fertilizerDeathTime;

public:
    /**
     * @brief Construct a new Plant Data object
     * @param name Species name
     * @param waterForState Water needed for state progression
     * @param fertilizerForState Fertilizer needed for state progression
     * @param waterInt Water interval in ticks
     * @param fertilizerInt Fertilizer interval in ticks
     * @param waterDeath Time without water until death
     * @param fertilizerDeath Time without fertilizer until death
     */
    PlantData(const std::string& name, int waterForState, int fertilizerForState,
              int waterInt, int fertilizerInt, int waterDeath, int fertilizerDeath);
    
    /**
     * @brief Copy constructor
     * @param other The PlantData to copy from
     */
    PlantData(const PlantData& other);

    // Getters
    std::string getSpeciesName() const { return speciesName; }
    int getWaterNeededForNextState() const { return waterNeededForNextState; }
    int getFertilizerNeededForNextState() const { return fertilizerNeededForNextState; }
    int getWaterInterval() const { return waterInterval; }
    int getFertilizerInterval() const { return fertilizerInterval; }
    int getWaterDeathTime() const { return waterDeathTime; }
    int getFertilizerDeathTime() const { return fertilizerDeathTime; }
    bool isOutside() const { return outside; }
    bool isLowLight() const { return lowLight; }
    bool isLowWater() const { return lowWater; }
    bool isBrightColour() const { return brightColour; }
    bool isLowCare() const { return lowCare; }
    
    /**
     * @brief Get pointer to this plant data
     * @return PlantData* Pointer to this plant data instance
     */
    PlantData* getPlantData(){return this;};
};

#endif
