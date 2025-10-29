#include "Plant.h"
#include <iostream>

Plant::Plant(const std::string& plantId, const std::string& plantName, 
             std::shared_ptr<PlantData> data)
    : id(plantId), name(plantName), plantData(data),
      previousState("Seedling"),
      waterReceived(0), fertilizerReceived(0),
      ticksWithoutWater(0), ticksWithoutFertilizer(0) {
    
    state = std::make_unique<Seedling>();
}

Plant::Plant(const Plant& other) {
      id = "clone"; // change this
      name = other.name;
      if(other.plantData != nullptr) {
        plantData = std::make_unique<PlantData>(*other.plantData);
      } else {
        plantData = nullptr;
      }
      previousState = "Seedling";
      waterReceived = 0;
      fertilizerReceived = 0;
      ticksWithoutWater = 0;
      ticksWithoutFertilizer = 0;
    
    // Deep copy of the state
    if (other.state) {
        std::string stateName = other.state->getName();
        if (stateName == "Seedling") {
            state = std::make_unique<Seedling>();
        } else if (stateName == "Growing") {
            state = std::make_unique<Growing>();
        } else if (stateName == "Mature") {
            state = std::make_unique<Mature>();
        } else if (stateName == "ReadyToSell") {
            state = std::make_unique<ReadyToSell>();
        } else if (stateName == "Dying") {
            state = std::make_unique<Dying>(other.previousState);
        } else if (stateName == "Dead") {
            state = std::make_unique<Dead>();
        }
    }
}

bool Plant::shouldEnterDyingState() const {
    // Enter dying state if plant needs water OR fertilizer OR both
    // And it's not already dying or dead
    return (needsWater() || needsFertilizer()) && !isDying() && !isDead();
}

void Plant::update() {
    if (isDead()) return;
    
    ticksWithoutWater++;
    ticksWithoutFertilizer++;
    
    // Check for actual death FIRST (before any state transitions)
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
    
    // Check if plant should enter dying state
    if (shouldEnterDyingState() && !isDying()) {
        std::string currentState = getStateName();
        setState(std::make_unique<Dying>(currentState));
        std::cout << "⚠️ " << name << " is DYING! Needs immediate care!\n";
        return;
    }
    
    // Check for recovery from Dying state during update
    if (isDying()) {
        recoverFromDying();
        return; // If we recovered, don't process normal state transitions this update
    }
    
    if (state) {
        state->handle(this);
    }
}

void Plant::water() {
    waterReceived++;
    ticksWithoutWater = 0;
    std::cout << "💧 " << name << " was watered. Total: " << waterReceived << std::endl;
    
    // Check for recovery from Dying state immediately
    if (isDying()) {
        recoverFromDying();
    }
}

void Plant::fertilize() {
    fertilizerReceived++;
    ticksWithoutFertilizer = 0;
    std::cout << "🌱 " << name << " was fertilized. Total: " << fertilizerReceived << std::endl;
    
    // Check for recovery from Dying state immediately
    if (isDying()) {
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
    // Recover if we no longer need water AND no longer need fertilizer
    // (i.e., we have both water and fertilizer)
    if (!needsWater() && !needsFertilizer()) {
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
}