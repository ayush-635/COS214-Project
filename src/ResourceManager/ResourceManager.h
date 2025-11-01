#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>

class ResourceManager {
private:
    int waterLevel;
    int waterCapacity;
    int fertilizerLevel;
    int fertilizerCapacity;

public:
    ResourceManager();
    ~ResourceManager();
    
    // Simplified facade methods
    bool useWater(int amount);
    bool useFertilizer(int amount);
    bool refillWater();
    bool refillFertilizer();
    bool refillAll();
    
    // Status methods
    int getWaterLevel() const { return waterLevel; }
    int getWaterCapacity() const { return waterCapacity; }
    int getFertilizerLevel() const { return fertilizerLevel; }
    int getFertilizerCapacity() const { return fertilizerCapacity; }
    
    void displayStatus() const;
};

#endif