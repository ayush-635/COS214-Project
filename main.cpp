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

#include "src/PlantFactory/PlantFactory.h"
#include "src/SucculentFactory/SucculentFactory.h"

int main() {
    // Initialize flyweight factory
    PlantDataFactory::initializeFactory();
    
    // Get game manager (singleton)
    Game* game = Game::getInstance();

    PlantFactory* succulentFactory = new SucculentFactory();
    succulentFactory->addPlantPrototype(new SucculentPlant("PrototypeSucculent", "Prototype Succulent", PlantDataFactory::getPlantData("SucculentPlant")));
    Plant* p = succulentFactory->createPlant("Prototype Succulent");

    // Create plants with different requirements - including 2 of the same type
    game->addPlant(std::make_unique<FlowerPlant>("F1", "Red Rose", PlantDataFactory::getPlantData("FlowerPlant")));
    game->addPlant(std::make_unique<FlowerPlant>("F2", "Pink Rose", PlantDataFactory::getPlantData("FlowerPlant"))); // Second rose
    game->addPlant(std::make_unique<TreePlant>("T1", "Oak Tree", PlantDataFactory::getPlantData("TreePlant")));
    game->addPlant(std::make_unique<HerbPlant>("H1", "Basil", PlantDataFactory::getPlantData("HerbPlant")));
    game->addPlant(std::make_unique<GrassPlant>("G1", "Lawn Grass", PlantDataFactory::getPlantData("GrassPlant")));
    game->addPlant(std::make_unique<SucculentPlant>("C1", "Golden Barrel", PlantDataFactory::getPlantData("SucculentPlant")));
    game->addPlant(std::unique_ptr<Plant>(p));
}