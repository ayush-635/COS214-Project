#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <memory>
#include "src/PlantData/PlantData.h"
#include "src/PlantState/PlantState.h"  // Abstract interface
#include "src/Seedling/Seedling.h"    // Concrete states
#include "src/Growing/Growing.h"
#include "src/Mature/Mature.h"
#include "src/ReadyToSell/ReadyToSell.h"
#include "src/Dead/Dead.h"

class CareVisitor;

class Plant {
protected:
    std::string id;
    std::string name;
    std::shared_ptr<PlantData> plantData;
    std::unique_ptr<PlantState> state;
    
    int waterReceived;
    int fertilizerReceived;
    int ticksWithoutWater;
    int ticksWithoutFertilizer;

public:
    Plant(const std::string& plantId, const std::string& plantName, 
          std::shared_ptr<PlantData> data);
    virtual ~Plant() = default;
    
    virtual void update();
    void water();
    void fertilize();
    
    void setState(std::unique_ptr<PlantState> newState);
    std::string getStateName() const;
    
    // Visitor pattern
    virtual void accept(CareVisitor& visitor) = 0;
    
    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpeciesName() const { return plantData->getSpeciesName(); }
    int getWaterReceived() const { return waterReceived; }
    int getFertilizerReceived() const { return fertilizerReceived; }
    int getWaterNeededForNextState() const { return plantData->getWaterNeededForNextState(); }
    int getFertilizerNeededForNextState() const { return plantData->getFertilizerNeededForNextState(); }
    int getWaterInterval() const { return plantData->getWaterInterval(); }
    int getFertilizerInterval() const { return plantData->getFertilizerInterval(); }
    int getWaterDeathTime() const { return plantData->getWaterDeathTime(); }
    int getFertilizerDeathTime() const { return plantData->getFertilizerDeathTime(); }
    
    // Condition checkers
    bool needsWater() const { return ticksWithoutWater >= plantData->getWaterInterval(); }
    bool needsFertilizer() const { return ticksWithoutFertilizer >= plantData->getFertilizerInterval(); }
    bool isDead() const { return getStateName() == "Dead"; }
    bool isInDanger() const { 
        return ticksWithoutWater >= plantData->getWaterDeathTime() - 3 || 
               ticksWithoutFertilizer >= plantData->getFertilizerDeathTime() - 3; 
    }
    
    // Progress calculations
    int getWaterRemaining() const { return plantData->getWaterNeededForNextState() - waterReceived; }
    int getFertilizerRemaining() const { return plantData->getFertilizerNeededForNextState() - fertilizerReceived; }
    
    // For debugging/status
    int getTicksWithoutWater() const { return ticksWithoutWater; }
    int getTicksWithoutFertilizer() const { return ticksWithoutFertilizer; }
};

#endif