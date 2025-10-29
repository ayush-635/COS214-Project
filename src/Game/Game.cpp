#include "Game.h"
#include "../FlowerPlant/FlowerPlant.h"
#include "../TreePlant/TreePlant.h"
#include "../HerbPlant/HerbPlant.h"
#include "../GrassPlant/GrassPlant.h"
#include "../SucculentPlant/SucculentPlant.h"
#include <iostream>
#include <algorithm>

Game* Game::instance = nullptr;

Game::Game() {
    std::cout << "Game initialized.\n";
}

Game* Game::getInstance() {
    if (!instance) {
        instance = new Game();
    }
    return instance;
}

void Game::addPlant(std::unique_ptr<Plant> plant) {
    plants.push_back(std::move(plant));
    std::cout << "Added plant: " << plants.back()->getName() << std::endl;
}

void Game::removePlant(const std::string& plantId) {
    plants.erase(std::remove_if(plants.begin(), plants.end(),
        [&](const std::unique_ptr<Plant>& p) { return p->getId() == plantId; }),
        plants.end());
}

Plant* Game::getPlant(const std::string& plantId) {
    for (auto& plant : plants) {
        if (plant->getId() == plantId) {
            return plant.get();
        }
    }
    return nullptr;
}

void Game::update() {
    for (auto& plant : plants) {
        plant->update();
    }
    
    static int updateCount = 0;
    updateCount++;
    if (updateCount >= 5) {
        checkPlantConditions();
        updateCount = 0;
    }
}

void Game::checkPlantConditions() {
    healthVisitor.clearReports();
    
    for (auto& plant : plants) {
        plant->accept(healthVisitor);
    }
    
    healthVisitor.printReport();
}

void Game::waterPlant(const std::string& plantId) {
    Plant* plant = getPlant(plantId);
    if (plant) {
        plant->water();
    }
}

void Game::fertilizePlant(const std::string& plantId) {
    Plant* plant = getPlant(plantId);
    if (plant) {
        plant->fertilize();
    }
}

//might remove later
void Game::displayGameStatus() const {
    std::cout << "\n=== GARDEN STATUS ===" << std::endl;
    std::cout << "Total Plants: " << plants.size() << std::endl;
    
    for (const auto& plant : plants) {
        std::cout << "• " << plant->getName() 
                  << " [" << plant->getStateName() << "]"
                  << " | Water: " << plant->getWaterReceived() << "/" << plant->getWaterNeededForNextState()
                  << " | Fertilizer: " << plant->getFertilizerReceived() << "/" << plant->getFertilizerNeededForNextState() << std::endl;
    }

}