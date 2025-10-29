#include "src/Game/Game.h"
#include "src/Plant/Plant.h"
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
#include "src/FlowerFactory/FlowerFactory.h"

int main() {
    // Initialize flyweight factory
    // PlantDataFactory::initializeFactory();
    
    // // Get game manager (singleton)
    // Game* game = Game::getInstance();

    // PlantFactory* flowerFactory = new FlowerFactory();
    // flowerFactory->addPlantPrototype(new FlowerPlant("Test_Flower_Prototype 1", "Prototype Flower 1", PlantDataFactory::getPlantData("FlowerPlant")));
    // flowerFactory->addPlantPrototype(new FlowerPlant("Test_Flower_Prototype 2", "Prototype Flower 2", PlantDataFactory::getPlantData("FlowerPlant")));

    // Plant* p1 = flowerFactory->createPlant("Prototype Flower 1");
    // Plant* p2 = flowerFactory->createPlant("Prototype Flower 2");

    // std::cout << p1 << std::endl;

    // game->addPlant(std::unique_ptr<Plant>(p1));
    // game->addPlant(std::unique_ptr<Plant>(p2));

    // game->displayGameStatus();

    Plant* flowerPrototype = new FlowerPlant("F_Proto", "Flower Prototype", nullptr);
    Plant* clonedFlower = flowerPrototype->clone();
    auto data = PlantDataFactory::getPlantData("FlowerPlant");
    std::cout << data << std::endl;

    return 0;
}