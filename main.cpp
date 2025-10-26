#include "src/Game/Game.h"
#include "src/PlantData/PlantData.h"
#include "src/PlantDataFactory/PlantDataFactory.h"
#include "src/FlowerPlant/FlowerPlant.h"
#include "src/TreePlant/TreePlant.h"
#include "src/HerbPlant/HerbPlant.h"
#include "src/GrassPlant/GrassPlant.h"
#include "src/SucculentPlant/SucculentPlant.h"
#include "src/Seedling/Seedling.h"
#include "src/Growing/Growing.h"
#include "src/Mature/Mature.h"
#include "src/ReadyToSell/ReadyToSell.h"
#include "src/Dead/Dead.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Initialize flyweight factory
    PlantDataFactory::initializeFactory();
    
    // Get game manager (singleton)
    Game* game = Game::getInstance();
    
    // Create plants with different requirements - including 2 of the same type
    game->addPlant(std::make_unique<FlowerPlant>("F1", "Red Rose", PlantDataFactory::getPlantData("FlowerPlant")));
    game->addPlant(std::make_unique<FlowerPlant>("F2", "Pink Rose", PlantDataFactory::getPlantData("FlowerPlant"))); // Second rose
    game->addPlant(std::make_unique<TreePlant>("T1", "Oak Tree", PlantDataFactory::getPlantData("TreePlant")));
    game->addPlant(std::make_unique<HerbPlant>("H1", "Basil", PlantDataFactory::getPlantData("HerbPlant")));
    game->addPlant(std::make_unique<GrassPlant>("G1", "Lawn Grass", PlantDataFactory::getPlantData("GrassPlant")));
    game->addPlant(std::make_unique<SucculentPlant>("C1", "Golden Barrel", PlantDataFactory::getPlantData("SucculentPlant")));
    
    std::cout << "\n🌿 PLANT GAME - STATE PROGRESSION DEMO 🌿" << std::endl;
    std::cout << "Watch plants grow through different states!\n" << std::endl;
    
    // Display plant requirements - use the correct keys from factory
    std::cout << "PLANT GROWTH REQUIREMENTS:" << std::endl;
    auto flowerData = PlantDataFactory::getPlantData("FlowerPlant");
    auto treeData = PlantDataFactory::getPlantData("TreePlant");
    auto herbData = PlantDataFactory::getPlantData("HerbPlant");
    auto grassData = PlantDataFactory::getPlantData("GrassPlant");
    auto succulentData = PlantDataFactory::getPlantData("SucculentPlant");
    
    std::cout << "🌸 Flower: " << flowerData->getWaterNeededForNextState() << " waters + " 
              << flowerData->getFertilizerNeededForNextState() << " fertilizers to grow | Water every " 
              << flowerData->getWaterInterval() << " ticks" << std::endl;
              
    std::cout << "🌳 Tree: " << treeData->getWaterNeededForNextState() << " waters + " 
              << treeData->getFertilizerNeededForNextState() << " fertilizers to grow | Water every " 
              << treeData->getWaterInterval() << " ticks" << std::endl;
              
    std::cout << "🌿 Herb: " << herbData->getWaterNeededForNextState() << " waters + " 
              << herbData->getFertilizerNeededForNextState() << " fertilizers to grow | Water every " 
              << herbData->getWaterInterval() << " ticks" << std::endl;
              
    std::cout << "🟢 Grass: " << grassData->getWaterNeededForNextState() << " waters + " 
              << grassData->getFertilizerNeededForNextState() << " fertilizers to grow | Water every " 
              << grassData->getWaterInterval() << " ticks" << std::endl;

    std::cout << "🌵 Succulent: " << succulentData->getWaterNeededForNextState() << " waters + " 
              << succulentData->getFertilizerNeededForNextState() << " fertilizers to grow | Water every " 
              << succulentData->getWaterInterval() << " ticks" << std::endl;
    std::cout << std::endl;

    std::cout << "NOTE: Two Flower plants (Red Rose and Pink Rose) to show multiple plants of same type!\n" << std::endl;
    
    // Game loop - each iteration = 1 "tick"
    for (int tick = 1; tick <= 40; tick++) {
        std::cout << "\n--- Tick " << tick << " ---" << std::endl;
        
        // Update game state
        game->update();
        
        // Strategic player actions to demonstrate state progression
        if (tick == 3) {
            std::cout << "\n>>> Early care for fast-growing plants <<<" << std::endl;
            game->waterPlant("H1"); // Water Herb (grows fast)
            game->waterPlant("G1"); // Water Grass (grows fast)
            game->fertilizePlant("G1"); // Fertilize Grass
        }
        
        if (tick == 5) {
            std::cout << "\n>>> Focus on Flowers <<<" << std::endl;
            game->waterPlant("F1"); // Water Red Flower
            game->waterPlant("F2"); // Water Pink Flower
            game->fertilizePlant("F1"); // Fertilize Red Flower
        }
        
        if (tick == 8) {
            std::cout << "\n>>> General plant care <<<" << std::endl;
            game->waterPlant("T1"); // Water Tree
            game->waterPlant("H1"); // Water Herb again
            game->fertilizePlant("H1"); // Fertilize Herb
        }
        
        if (tick == 10) {
            std::cout << "\n>>> More Flower care <<<" << std::endl;
            game->waterPlant("F1");
            game->waterPlant("F2");
            game->fertilizePlant("F2"); // Fertilize Pink Flower
        }
        
        if (tick == 12) {
            std::cout << "\n>>> First succulent care <<<" << std::endl;
            game->waterPlant("C1"); // Water Succulent
            game->fertilizePlant("C1"); // Fertilize Succulent
        }
        
        if (tick == 15) {
            std::cout << "\n>>> Final Flower push <<<" << std::endl;
            game->waterPlant("F1");
            game->waterPlant("F2");
            game->fertilizePlant("F1");
            game->fertilizePlant("F2");
        }
        
        if (tick == 18) {
            std::cout << "\n>>> Tree and Herb care <<<" << std::endl;
            game->waterPlant("T1");
            game->fertilizePlant("T1");
            game->waterPlant("H1");
            game->fertilizePlant("H1");
        }
        
        if (tick == 22) {
            std::cout << "\n>>> Maintenance watering <<<" << std::endl;
            game->waterPlant("F1");
            game->waterPlant("F2");
            game->waterPlant("G1");
            game->waterPlant("C1"); // Water Succulent again
        }
        
        if (tick == 25) {
            std::cout << "\n>>> Prevent plant deaths <<<" << std::endl;
            game->fertilizePlant("F1");
            game->fertilizePlant("F2");
            game->fertilizePlant("T1");
            game->fertilizePlant("C1");
        }
        
        if (tick == 28) {
            std::cout << "\n>>> Late game care <<<" << std::endl;
            game->waterPlant("T1");
            game->fertilizePlant("T1");
            game->waterPlant("F1");
            game->waterPlant("F2");
            game->waterPlant("C1"); // Final succulent care
        }
        
        if (tick == 32) {
            std::cout << "\n>>> Final fertilizer <<<" << std::endl;
            game->fertilizePlant("F1");
            game->fertilizePlant("F2");
            game->fertilizePlant("T1");
            game->fertilizePlant("C1");
        }
        
        // Display full status every 8 ticks to see progression
        if (tick % 8 == 0) {
            game->displayGameStatus();
        }
        
        // Wait a bit between ticks
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "🎮 FINAL GARDEN STATUS" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    game->displayGameStatus();
    
    // Show which plants reached which states
    std::cout << "\nPLANT STATE PROGRESSION SUMMARY:" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    for (const auto& plant : game->getPlants()) {
        std::cout << "• " << plant->getName() << ": " << plant->getStateName() 
                  << " (Water: " << plant->getWaterReceived() << "/" << plant->getWaterNeededForNextState()
                  << ", Fertilizer: " << plant->getFertilizerReceived() << "/" << plant->getFertilizerNeededForNextState() << ")" << std::endl;
    }
    
    return 0;
}