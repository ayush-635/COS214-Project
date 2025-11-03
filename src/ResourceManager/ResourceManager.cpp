#include "ResourceManager.h"

ResourceManager::ResourceManager() 
    : waterLevel(1000), waterCapacity(1000),
      fertilizerLevel(500), fertilizerCapacity(500) {
    std::cout << "🏪 Resource Storage Initialized" << std::endl;
    std::cout << "   💧 Water: " << waterLevel << "/" << waterCapacity << std::endl;
    std::cout << "   🌿 Fertilizer: " << fertilizerLevel << "/" << fertilizerCapacity << std::endl;
}

ResourceManager::~ResourceManager() {
    // Cleanup if needed
}

bool ResourceManager::useWater(int amount) {
    if (amount <= 0) return false;
    
    if (waterLevel >= amount) {
        waterLevel -= amount;
        std::cout << "💧 Used " << amount << " water (Remaining: " 
                  << waterLevel << "/" << waterCapacity << ")" << std::endl;
        return true;
    } else {
        std::cout << "❌ Insufficient water! Need " << amount 
                  << ", have " << waterLevel << std::endl;
        return false;
    }
}

bool ResourceManager::useFertilizer(int amount) {
    if (amount <= 0) return false;
    
    if (fertilizerLevel >= amount) {
        fertilizerLevel -= amount;
        std::cout << "🌿 Used " << amount << " fertilizer (Remaining: " 
                  << fertilizerLevel << "/" << fertilizerCapacity << ")" << std::endl;
        return true;
    } else {
        std::cout << "❌ Insufficient fertilizer! Need " << amount 
                  << ", have " << fertilizerLevel << std::endl;
        return false;
    }
}

bool ResourceManager::refillWater() {
    waterLevel = waterCapacity;
    std::cout << "✅ Water storage refilled to " << waterCapacity << " units" << std::endl;
    return true;
}

bool ResourceManager::refillFertilizer() {
    fertilizerLevel = fertilizerCapacity;
    std::cout << "✅ Fertilizer storage refilled to " << fertilizerCapacity << " units" << std::endl;
    return true;
}

bool ResourceManager::refillAll() {
    std::cout << "\n🔄 REFILLING ALL RESOURCES..." << std::endl;
    refillWater();
    refillFertilizer();
    std::cout << "✅ All resources refilled!\n" << std::endl;
    return true;
}

void ResourceManager::displayStatus() const {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║       📦 RESOURCE STATUS 📦            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::cout << "💧 Water: " << waterLevel << "/" << waterCapacity 
              << " (" << (waterLevel * 100 / waterCapacity) << "%)" << std::endl;
    std::cout << "🌿 Fertilizer: " << fertilizerLevel << "/" << fertilizerCapacity 
              << " (" << (fertilizerLevel * 100 / fertilizerCapacity) << "%)" << std::endl;
    std::cout << "════════════════════════════════════════" << std::endl;
}