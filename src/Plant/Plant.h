#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <memory>
#include "../PlantData/PlantData.h"
#include "../PlantState/PlantState.h"
#include "../Seedling/Seedling.h"
#include "../Growing/Growing.h"
#include "../Mature/Mature.h"
#include "../ReadyToSell/ReadyToSell.h"
#include "../Dying/Dying.h"
#include "../Dead/Dead.h"

class CareVisitor;

/**
 * @class Plant
 * @brief Base class for all plants in the game
 */
class Plant {
protected:
    std::string id; ///< Unique identifier for the plant
    std::string name; ///< Display name of the plant
    std::shared_ptr<PlantData> plantData; ///< Shared configuration data
    std::unique_ptr<PlantState> state; ///< Current growth state
    std::string previousState; ///< State before entering Dying state
    
    int waterReceived; ///< Total water received in current state
    int fertilizerReceived; ///< Total fertilizer received in current state
    int ticksWithoutWater; ///< Ticks since last watering
    int ticksWithoutFertilizer; ///< Ticks since last fertilization

public:
    /**
     * @brief Construct a new Plant object
     * @param plantId Unique identifier for the plant
     * @param plantName Display name of the plant
     * @param data Shared plant data configuration
     */
    Plant(const std::string& plantId, const std::string& plantName, 
          std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other The Plant to copy from
     */
    Plant(const Plant& other);
    virtual ~Plant() = default;

    /**
     * @brief Create a clone of this plant
     * @return Plant* Pointer to the cloned plant
     */
    virtual Plant* clone() = 0;
    
    virtual void update();
    
    /**
     * @brief Water the plant
     */
    void water();
    
    /**
     * @brief Fertilize the plant
     */
    void fertilize();
    
    /**
     * @brief Change the plant's current state
     * @param newState The new state to transition to
     */
    void setState(std::unique_ptr<PlantState> newState);
    
    /**
     * @brief Get the name of the current state
     * @return std::string Name of the current state
     */
    std::string getStateName() const;
    
    /**
     * @brief Check if plant should enter Dying state
     * @return bool True if plant meets dying conditions
     */
    bool shouldEnterDyingState() const;
    
    /**
     * @brief Attempt to recover plant from Dying state
     */
    void recoverFromDying();
    
    /**
     * @brief Accept a care visitor
     * @param visitor The care visitor to accept
     */
    virtual void accept(CareVisitor& visitor) = 0;
    
    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpeciesName() const { return plantData->getSpeciesName(); }
    std::string getPreviousState() const { return previousState; }
    int getWaterReceived() const { return waterReceived; }
    int getFertilizerReceived() const { return fertilizerReceived; }
    int getWaterNeededForNextState() const { return plantData->getWaterNeededForNextState(); }
    int getFertilizerNeededForNextState() const { return plantData->getFertilizerNeededForNextState(); }
    int getWaterInterval() const { return plantData->getWaterInterval(); }
    int getFertilizerInterval() const { return plantData->getFertilizerInterval(); }
    int getWaterDeathTime() const { return plantData->getWaterDeathTime(); }
    int getFertilizerDeathTime() const { return plantData->getFertilizerDeathTime(); }
    
    /**
     * @brief Set the plant's ID
     * @param newID The new ID to set
     */
    void setID(std::string newID) { id = newID; }

    // Condition checkers
    bool needsWater() const { return ticksWithoutWater >= plantData->getWaterInterval(); }
    bool needsFertilizer() const { return ticksWithoutFertilizer >= plantData->getFertilizerInterval(); }
    bool isDead() const { return getStateName() == "Dead"; }
    bool isDying() const { return getStateName() == "Dying"; }
    bool isInDanger() const { 
        return ticksWithoutWater >= plantData->getWaterDeathTime() - 3 || 
               ticksWithoutFertilizer >= plantData->getFertilizerDeathTime() - 3; 
    }
    
    // Progress calculations
    int getWaterRemaining() const { return plantData->getWaterNeededForNextState() - waterReceived; }
    int getFertilizerRemaining() const { return plantData->getFertilizerNeededForNextState() - fertilizerReceived; }
    
    // For status
    int getTicksWithoutWater() const { return ticksWithoutWater; }
    int getTicksWithoutFertilizer() const { return ticksWithoutFertilizer; }

    /**
     * @brief Get the plant data
     * @return std::shared_ptr<PlantData> Shared pointer to plant data
     */
    std::shared_ptr<PlantData> getPlantData(){return plantData;};
};

#endif
