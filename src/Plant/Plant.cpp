#include "Plant.h"
#include <iostream>

Plant::Plant(const std::string& plantId, const std::string& plantName, 
             std::shared_ptr<PlantData> data)
    : id(plantId), name(plantName), plantData(data),
      waterReceived(0), fertilizerReceived(0),
      ticksWithoutWater(0), ticksWithoutFertilizer(0),
      previousState("Seedling") {
    
    state = std::make_unique<Seedling>();
}

bool Plant::shouldEnterDyingState() const {
    // Enter dying state if plant needs both water AND fertilizer
    // And it's not already dying or dead
    return needsWater() && needsFertilizer() && !isDying() && !isDead();
}

void Plant::update() {
    if (isDead()) return;
    
    ticksWithoutWater++;
    ticksWithoutFertilizer++;
    
    // Check if plant should enter dying state
    if (shouldEnterDyingState() && !isDying()) {
        std::string currentState = getStateName();
        setState(std::make_unique<Dying>(currentState));
        std::cout << "⚠️ " << name << " is DYING! Needs immediate care!\n";
        return;
    }
    
    // Check for actual death (only if not recovering from dying)
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
    
    // Immediate recovery from Dying state if watered and no longer needs fertilizer
    if (isDying() && !needsFertilizer()) {
        recoverFromDying();
    }
}

void Plant::fertilize() {
    fertilizerReceived++;
    ticksWithoutFertilizer = 0;
    std::cout << "🌱 " << name << " was fertilized. Total: " << fertilizerReceived << std::endl;
    
    // Immediate recovery from Dying state if fertilized and no longer needs water
    if (isDying() && !needsWater()) {
        recoverFromDying();
    }
}

void Plant::setState(std::unique_ptr<PlantState> newState) {
    // Store current state as previous state before changing (unless it's Dying)
    if (state && state->getName() != "Dying") {
        previousState = state->getName();
    }
    state = std::move(newState);
}

std::string Plant::getStateName() const {
    return state ? state->getName() : "Unknown";
}

void Plant::recoverFromDying() {
    if (previousState == "Seedling") {
        setState(std::make_unique<Seedling>());
        std::cout << "💚 " << name << " recovered from Dying to Seedling!\n";
    } else if (previousState == "Growing") {
        setState(std::make_unique<Growing>());
        std::cout << "💚 " << name << " recovered from Dying to Growing!\n";
    } else if (previousState == "Mature") {
        setState(std::make_unique<Mature>());
        std::cout << "💚 " << name << " recovered from Dying to Mature!\n";
    } else if (previousState == "ReadyToSell") {
        setState(std::make_unique<ReadyToSell>());
        std::cout << "💚 " << name << " recovered from Dying to ReadyToSell!\n";
    }
}