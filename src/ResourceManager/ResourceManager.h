/**
 * @file ResourceManager.h
 * @author Ayush Sanjith
 * @brief Header file for the ResourceManager class
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>

/**
 * @class ResourceManager
 * @brief Manages water and fertilizer resources
 */
class ResourceManager {
private:
    int waterLevel;         /**< Current water level */
    int waterCapacity;      /**< Maximum water capacity */
    int fertilizerLevel;    /**< Current fertilizer level */
    int fertilizerCapacity; /**< Maximum fertilizer capacity */

public:
    /**
     * @brief Default constructor
     */
    ResourceManager();
    
    /**
     * @brief Destructor
     */
    ~ResourceManager();
    
    // Simplified facade methods
    /**
     * @brief Use water
     * @param amount Amount to use
     * @return True if successful
     */
    bool useWater(int amount);
    
    /**
     * @brief Use fertilizer
     * @param amount Amount to use
     * @return True if successful
     */
    bool useFertilizer(int amount);
    
    /**
     * @brief Refill water
     * @return True if successful
     */
    bool refillWater();
    
    /**
     * @brief Refill fertilizer
     * @return True if successful
     */
    bool refillFertilizer();
    
    /**
     * @brief Refill all resources
     * @return True if successful
     */
    bool refillAll();
    
    // Status methods
    /**
     * @brief Get water level
     * @return Water level
     */
    int getWaterLevel() const { return waterLevel; }
    
    /**
     * @brief Get water capacity
     * @return Water capacity
     */
    int getWaterCapacity() const { return waterCapacity; }
    
    /**
     * @brief Get fertilizer level
     * @return Fertilizer level
     */
    int getFertilizerLevel() const { return fertilizerLevel; }
    
    /**
     * @brief Get fertilizer capacity
     * @return Fertilizer capacity
     */
    int getFertilizerCapacity() const { return fertilizerCapacity; }
    
    /**
     * @brief Display resource status
     */
    void displayStatus() const;
};

#endif