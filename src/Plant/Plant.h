/**
 * @file Plant.h
 * @brief Header file for the Plant class
 */

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
 * @brief Base class representing a plant with state management
 */
class Plant {
protected:
    std::string id;                                 /**< Unique identifier for the plant */
    std::string name;                               /**< Name of the plant */
    std::shared_ptr<PlantData> plantData;           /**< Shared pointer to plant data */
    std::unique_ptr<PlantState> state;              /**< Unique pointer to current plant state */
    std::string previousState;                      /**< State before entering Dying state */
    
    int waterReceived;                              /**< Amount of water received */
    int fertilizerReceived;                         /**< Amount of fertilizer received */
    int ticksWithoutWater;                          /**< Ticks without water */
    int ticksWithoutFertilizer;                     /**< Ticks without fertilizer */

public:
    /**
     * @brief Constructor for Plant
     * @param plantId Unique identifier for the plant
     * @param plantName Name of the plant
     * @param data Shared pointer to plant data
     */
    Plant(const std::string& plantId, const std::string& plantName, 
          std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other Plant to copy from
     */
    Plant(const Plant& other);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Plant() = default;

    /**
     * @brief Pure virtual clone method
     * @return Pointer to cloned plant
     */
    virtual Plant* clone() = 0;
    
    /**
     * @brief Update plant state and conditions
     */
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
     * @brief Set the plant state
     * @param newState Unique pointer to new state
     */
    void setState(std::unique_ptr<PlantState> newState);
    
    /**
     * @brief Get the current state name
     * @return State name as string
     */
    std::string getStateName() const;
    
    /**
     * @brief Check if plant should enter dying state
     * @return True if plant should enter dying state
     */
    bool shouldEnterDyingState() const;
    
    /**
     * @brief Recover plant from dying state
     */
    void recoverFromDying();
    
    /**
     * @brief Pure virtual method to accept care visitor
     * @param visitor Reference to care visitor
     */
    virtual void accept(CareVisitor& visitor) = 0;
    
    // Getters
    /**
     * @brief Get plant ID
     * @return Plant ID
     */
    std::string getId() const { return id; }
    
    /**
     * @brief Get plant name
     * @return Plant name
     */
    std::string getName() const { return name; }
    
    /**
     * @brief Get species name
     * @return Species name
     */
    std::string getSpeciesName() const { return plantData->getSpeciesName(); }
    
    /**
     * @brief Get previous state
     * @return Previous state name
     */
    std::string getPreviousState() const { return previousState; }
    
    /**
     * @brief Get water received
     * @return Water received count
     */
    int getWaterReceived() const { return waterReceived; }
    
    /**
     * @brief Get fertilizer received
     * @return Fertilizer received count
     */
    int getFertilizerReceived() const { return fertilizerReceived; }
    
    /**
     * @brief Get water needed for next state
     * @return Water needed for next state
     */
    int getWaterNeededForNextState() const { return plantData->getWaterNeededForNextState(); }
    
    /**
     * @brief Get fertilizer needed for next state
     * @return Fertilizer needed for next state
     */
    int getFertilizerNeededForNextState() const { return plantData->getFertilizerNeededForNextState(); }
    
    /**
     * @brief Get water interval
     * @return Water interval
     */
    int getWaterInterval() const { return plantData->getWaterInterval(); }
    
    /**
     * @brief Get fertilizer interval
     * @return Fertilizer interval
     */
    int getFertilizerInterval() const { return plantData->getFertilizerInterval(); }
    
    /**
     * @brief Get water death time
     * @return Water death time
     */
    int getWaterDeathTime() const { return plantData->getWaterDeathTime(); }
    
    /**
     * @brief Get fertilizer death time
     * @return Fertilizer death time
     */
    int getFertilizerDeathTime() const { return plantData->getFertilizerDeathTime(); }
    
    /**
     * @brief Set plant ID
     * @param newID New plant ID
     */
    void setID(std::string newID) { id = newID; }

    // Condition checkers
    /**
     * @brief Check if plant needs water
     * @return True if plant needs water
     */
    bool needsWater() const { return ticksWithoutWater >= plantData->getWaterInterval(); }
    
    /**
     * @brief Check if plant needs fertilizer
     * @return True if plant needs fertilizer
     */
    bool needsFertilizer() const { return ticksWithoutFertilizer >= plantData->getFertilizerInterval(); }
    
    /**
     * @brief Check if plant is dead
     * @return True if plant is dead
     */
    bool isDead() const { return getStateName() == "Dead"; }
    
    /**
     * @brief Check if plant is dying
     * @return True if plant is dying
     */
    bool isDying() const { return getStateName() == "Dying"; }
    
    /**
     * @brief Check if plant is in danger
     * @return True if plant is in danger
     */
    bool isInDanger() const { 
        return ticksWithoutWater >= plantData->getWaterDeathTime() - 3 || 
               ticksWithoutFertilizer >= plantData->getFertilizerDeathTime() - 3; 
    }
    
    // Progress calculations
    /**
     * @brief Get water remaining for next state
     * @return Water remaining
     */
    int getWaterRemaining() const { return plantData->getWaterNeededForNextState() - waterReceived; }
    
    /**
     * @brief Get fertilizer remaining for next state
     * @return Fertilizer remaining
     */
    int getFertilizerRemaining() const { return plantData->getFertilizerNeededForNextState() - fertilizerReceived; }
    
    // For status
    /**
     * @brief Get ticks without water
     * @return Ticks without water
     */
    int getTicksWithoutWater() const { return ticksWithoutWater; }
    
    /**
     * @brief Get ticks without fertilizer
     * @return Ticks without fertilizer
     */
    int getTicksWithoutFertilizer() const { return ticksWithoutFertilizer; }

    /**
     * @brief Get plant data
     * @return Shared pointer to plant data
     */
    std::shared_ptr<PlantData> getPlantData(){return plantData;};
};

#endif