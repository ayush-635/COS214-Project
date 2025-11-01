#include "../tests/doctest.h"

#include "../src/Plant/Plant.h"
#include "../src/FlowerPlant/FlowerPlant.h"
#include "../src/TreePlant/TreePlant.h"
#include "../src/HerbPlant/HerbPlant.h"
#include "../src/GrassPlant/GrassPlant.h"
#include "../src/SucculentPlant/SucculentPlant.h"   

#include "../src/PlantDataFactory/PlantDataFactory.h"

#include <iostream>

TEST_SUITE("Cloning of Prototypes") {
    TEST_CASE("Cloning FlowerPlant Prototype") {
        PlantDataFactory::initializeFactory();

        Plant* flowerPrototype = new FlowerPlant("F_Proto", "Flower Prototype", PlantDataFactory::getPlantData("FlowerPlant"));
        Plant* clonedFlower = flowerPrototype->clone();

        CHECK(clonedFlower->getName() == "Flower Prototype");
        CHECK(clonedFlower->getStateName() == "Seedling");
        CHECK(clonedFlower->getSpeciesName() == flowerPrototype->getSpeciesName());
        CHECK(clonedFlower->getWaterNeededForNextState() == flowerPrototype->getWaterNeededForNextState());
        CHECK(clonedFlower->getFertilizerNeededForNextState() == flowerPrototype->getFertilizerNeededForNextState());
        CHECK(clonedFlower->getWaterInterval() == flowerPrototype->getWaterInterval());
        CHECK(clonedFlower->getFertilizerInterval() == flowerPrototype->getFertilizerInterval());
        CHECK(clonedFlower->getWaterDeathTime() == flowerPrototype->getWaterDeathTime());
        CHECK(clonedFlower->getFertilizerDeathTime() == flowerPrototype->getFertilizerDeathTime());
        CHECK(clonedFlower->getId() == "clone");

        delete flowerPrototype;
        delete clonedFlower;
    }

    TEST_CASE("Cloning TreePlant Prototype") {
        PlantDataFactory::initializeFactory();

        Plant* treePrototype = new TreePlant("T_Proto", "Tree Prototype", PlantDataFactory::getPlantData("TreePlant"));
        Plant* clonedTree = treePrototype->clone();
        
        CHECK(clonedTree->getName() == "Tree Prototype");
        CHECK(clonedTree->getStateName() == "Seedling");
        CHECK(clonedTree->getSpeciesName() == treePrototype->getSpeciesName());
        CHECK(clonedTree->getWaterNeededForNextState() == treePrototype->getWaterNeededForNextState());
        CHECK(clonedTree->getFertilizerNeededForNextState() == treePrototype->getFertilizerNeededForNextState());
        CHECK(clonedTree->getWaterInterval() == treePrototype->getWaterInterval());
        CHECK(clonedTree->getFertilizerInterval() == treePrototype->getFertilizerInterval());
        CHECK(clonedTree->getWaterDeathTime() == treePrototype->getWaterDeathTime());
        CHECK(clonedTree->getFertilizerDeathTime() == treePrototype->getFertilizerDeathTime());
        CHECK(clonedTree->getId() == "clone");
        
        delete treePrototype;
        delete clonedTree;
    }

    TEST_CASE("Cloning HerbPlant Prototype") {
        Plant* herbPrototype = new HerbPlant("H_Proto", "Herb Prototype", PlantDataFactory::getPlantData("HerbPlant"));
        Plant* clonedHerb = herbPrototype->clone();
        
        CHECK(clonedHerb->getName() == "Herb Prototype");
        CHECK(clonedHerb->getStateName() == "Seedling");
        CHECK(clonedHerb->getSpeciesName() == herbPrototype->getSpeciesName());
        CHECK(clonedHerb->getWaterNeededForNextState() == herbPrototype->getWaterNeededForNextState());
        CHECK(clonedHerb->getFertilizerNeededForNextState() == herbPrototype->getFertilizerNeededForNextState());
        CHECK(clonedHerb->getWaterInterval() == herbPrototype->getWaterInterval());
        CHECK(clonedHerb->getFertilizerInterval() == herbPrototype->getFertilizerInterval());
        CHECK(clonedHerb->getWaterDeathTime() == herbPrototype->getWaterDeathTime());
        CHECK(clonedHerb->getFertilizerDeathTime() == herbPrototype->getFertilizerDeathTime());
        CHECK(clonedHerb->getId() == "clone");
        
        delete herbPrototype;
        delete clonedHerb;
    }

    TEST_CASE("Cloning GrassPlant Prototype") {
        Plant* grassPrototype = new GrassPlant("G_Proto", "Grass Prototype", PlantDataFactory::getPlantData("GrassPlant"));
        Plant* clonedGrass = grassPrototype->clone();
        
        CHECK(clonedGrass->getName() == "Grass Prototype");
        CHECK(clonedGrass->getStateName() == "Seedling");
        CHECK(clonedGrass->getSpeciesName() == grassPrototype->getSpeciesName());
        CHECK(clonedGrass->getWaterNeededForNextState() == grassPrototype->getWaterNeededForNextState());
        CHECK(clonedGrass->getFertilizerNeededForNextState() == grassPrototype->getFertilizerNeededForNextState());
        CHECK(clonedGrass->getWaterInterval() == grassPrototype->getWaterInterval());
        CHECK(clonedGrass->getFertilizerInterval() == grassPrototype->getFertilizerInterval());
        CHECK(clonedGrass->getWaterDeathTime() == grassPrototype->getWaterDeathTime());
        CHECK(clonedGrass->getFertilizerDeathTime() == grassPrototype->getFertilizerDeathTime());
        CHECK(clonedGrass->getId() == "clone");
        
        delete grassPrototype;
        delete clonedGrass;
    }   

    TEST_CASE("Cloning SucculentPlant Prototype") {
        Plant* succulentPrototype = new SucculentPlant("S_Proto", "Succulent Prototype", PlantDataFactory::getPlantData("SucculentPlant"));
        Plant* clonedSucculent = succulentPrototype->clone();
        
        CHECK(clonedSucculent->getName() == "Succulent Prototype");
        CHECK(clonedSucculent->getStateName() == "Seedling");
        CHECK(clonedSucculent->getSpeciesName() == succulentPrototype->getSpeciesName());
        CHECK(clonedSucculent->getWaterNeededForNextState() == succulentPrototype->getWaterNeededForNextState());
        CHECK(clonedSucculent->getFertilizerNeededForNextState() == succulentPrototype->getFertilizerNeededForNextState());
        CHECK(clonedSucculent->getWaterInterval() == succulentPrototype->getWaterInterval());
        CHECK(clonedSucculent->getFertilizerInterval() == succulentPrototype->getFertilizerInterval());
        CHECK(clonedSucculent->getWaterDeathTime() == succulentPrototype->getWaterDeathTime());
        CHECK(clonedSucculent->getFertilizerDeathTime() == succulentPrototype->getFertilizerDeathTime());
        CHECK(clonedSucculent->getId() == "clone");
        
        delete succulentPrototype;
        delete clonedSucculent;
    }
}