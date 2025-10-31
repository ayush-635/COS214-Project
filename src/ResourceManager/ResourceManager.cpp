#include "ResourceManager.h"
#include "../Storage/WaterStorage.h"
#include "../Storage/FertilizerStorage.h"

ResourceManager::ResourceManager() {
    // Initialize both storage subsystems
    waterStorage = new WaterStorage(1000);     // 1000 units water capacity
    fertilizerStorage = new FertilizerStorage(500);  // 500 units fertilizer capacity
}

ResourceManager::~ResourceManager() {
    delete waterStorage;
    delete fertilizerStorage;
}

bool ResourceManager::useWater(int amt) {
    // Simplified interface - delegates to water storage subsystem
    return waterStorage->use(amt);
}

bool ResourceManager::useFertilizer(int amt) {
    // Simplified interface - delegates to fertilizer storage subsystem
    return fertilizerStorage->use(amt);
}

bool ResourceManager::refillAll() {
    // Unified operation across multiple subsystems
    bool waterRefilled = waterStorage->refill();
    bool fertilizerRefilled = fertilizerStorage->refill();
    
    return (waterRefilled && fertilizerRefilled);
}

bool ResourceManager::upgradeAll() {
    // Unified operation across multiple subsystems
    bool waterUpgraded = waterStorage->upgrade();
    bool fertilizerUpgraded = fertilizerStorage->upgrade();
    
    return (waterUpgraded && fertilizerUpgraded);
}
