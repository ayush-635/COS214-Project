#include "Plant.h"
#include <iostream>

Plant::Plant(const std::string& plantId, const std::string& plantName, 
             std::shared_ptr<PlantData> data)
    : id(plantId), name(plantName), plantData(data),
      waterReceived(0), fertilizerReceived(0),
      ticksWithoutWater(0), ticksWithoutFertilizer(0) {
    
    state = std::make_unique<Seedling>();
}

void Plant::update() {
    if (isDead()) return;
    
    ticksWithoutWater++;
    ticksWithoutFertilizer++;
    
    if (ticksWithoutWater >= plantData->getWaterDeathTime() || 
        ticksWithoutFertilizer >= plantData->getFertilizerDeathTime()) {
        
        setState(std::make_unique<Dead>());
        if (ticksWithoutWater >= plantData->getWaterDeathTime()) {
            std::cout << "💀 " << name << " has died from thirst! (No water for " << ticksWithoutWater << " ticks)\n";
        } else {
            std::cout << "💀 " << name << " has died from hunger! (No fertilizer for " << ticksWithoutFertilizer << " ticks)\n";
        }
        return;
    }
    
    if (state) {
        state->handle(this);
    }
}

void Plant::water() {
    waterReceived++;
    ticksWithoutWater = 0;
    std::cout << "💧 " << name << " was watered. Total: " << waterReceived << std::endl;
}

void Plant::fertilize() {
    fertilizerReceived++;
    ticksWithoutFertilizer = 0;
    std::cout << "🌱 " << name << " was fertilized. Total: " << fertilizerReceived << std::endl;
}

void Plant::setState(std::unique_ptr<PlantState> newState) {
    state = std::move(newState);
}

std::string Plant::getStateName() const {
    return state ? state->getName() : "Unknown";
}