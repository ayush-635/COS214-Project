#include <iostream>
#include <memory>
#include "src/Game/Game.h"
#include "src/PlantDataFactory/PlantDataFactory.h"
#include "src/FlowerFactory/FlowerFactory.h"
#include "src/FlowerPlant/FlowerPlant.h"
#include "src/TreePlant/TreePlant.h"
#include "src/HerbPlant/HerbPlant.h"
#include "src/GrassPlant/GrassPlant.h"
#include "src/SucculentPlant/SucculentPlant.h"
#include "src/Inventory/Inventory.h"

int main() {
    std::cout << "=== Plant Nursery System ===" << std::endl;
    std::cout << "Initializing...\n" << std::endl;
    PlantDataFactory::initializeFactory();
    FlowerFactory* factory = new FlowerFactory();
    std::shared_ptr<PlantData> flowerData = PlantDataFactory::getPlantData("FlowerPlant");
    std::shared_ptr<PlantData> treeData = PlantDataFactory::getPlantData("TreePlant");
    std::shared_ptr<PlantData> herbData = PlantDataFactory::getPlantData("HerbPlant");
    std::shared_ptr<PlantData> grassData = PlantDataFactory::getPlantData("GrassPlant");
    std::shared_ptr<PlantData> succulentData = PlantDataFactory::getPlantData("SucculentPlant");
    factory->addPlantPrototype(new FlowerPlant("proto1", "FlowerPlant", flowerData));
    factory->addPlantPrototype(new TreePlant("proto2", "TreePlant", treeData));
    factory->addPlantPrototype(new HerbPlant("proto3", "HerbPlant", herbData));
    factory->addPlantPrototype(new GrassPlant("proto4", "GrassPlant", grassData));
    factory->addPlantPrototype(new SucculentPlant("proto5", "SucculentPlant", succulentData));
    
    std::cout << "\n=== Setting up Inventory ===" << std::endl;
    Inventory* inventory = Inventory::getInstance();
    inventory->setFactory(factory);
    inventory->addStockType(factory, "FlowerPlant", "Spring");
    inventory->addStockType(factory, "TreePlant", "All");
    inventory->addStockType(factory, "HerbPlant", "Spring");
    inventory->addStockType(factory, "GrassPlant", "Summer");
    inventory->addStockType(factory, "SucculentPlant", "All");
    inventory->restock("FlowerPlant", 10);
    inventory->restock("TreePlant", 5);
    inventory->restock("HerbPlant", 8);
    inventory->restock("GrassPlant", 12);
    inventory->restock("SucculentPlant", 15);
    
    std::cout << "\n=== Current Inventory ===" << std::endl;
    std::cout << "FlowerPlant: " << inventory->getStock("FlowerPlant") << std::endl;
    std::cout << "TreePlant: " << inventory->getStock("TreePlant") << std::endl;
    std::cout << "HerbPlant: " << inventory->getStock("HerbPlant") << std::endl;
    std::cout << "GrassPlant: " << inventory->getStock("GrassPlant") << std::endl;
    std::cout << "SucculentPlant: " << inventory->getStock("SucculentPlant") << std::endl;
    
    std::cout << "\nTesting Plant Creation" << std::endl;
    Plant* flower = factory->createPlant("FlowerPlant");
    if (flower) {
        std::cout << "Created: " << flower->getName() << std::endl;
        delete flower;
    }
    
    std::cout << "\n Testing Sales " << std::endl;
    std::cout << "Selling 3 FlowerPlants..." << std::endl;
    if (inventory->trySell("FlowerPlant", 3)) {
        std::cout << "Sale successful!" << std::endl;
        std::cout << "FlowerPlant stock now: " << inventory->getStock("FlowerPlant") << std::endl;
    }
    
    std::cout << "\n=== Testing Game System ===" << std::endl;
    Game* game = Game::getInstance();
    
    std::unique_ptr<Plant> plant1(factory->createPlant("SucculentPlant"));
    if (plant1) {
        game->addPlant(std::move(plant1));
    }
    
    std::unique_ptr<Plant> plant2(factory->createPlant("HerbPlant"));
    if (plant2) {
        game->addPlant(std::move(plant2));
    }
    std::cout << "\nSimulating Growth " << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "\n--- Update " << (i+1) << " ---" << std::endl;
        game->waterPlant("proto5");
        game->fertilizePlant("proto5");
        game->update();
    }
    
    game->displayGameStatus();
    
    delete factory;
    
    std::cout << "\n=== System Shutdown ===" << std::endl;
    return 0;
}