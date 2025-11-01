#include "../tests/doctest.h"

#include "../src/Plant/Plant.h"
#include "../src/PlantFactory/PlantFactory.h"

#include "../src/FlowerPlant/FlowerPlant.h"
#include "../src/FlowerFactory/FlowerFactory.h"

#include "../src/TreePlant/TreePlant.h"
#include "../src/TreeFactory/TreeFactory.h"

#include "../src/HerbPlant/HerbPlant.h"
#include "../src/HerbFactory/HerbFactory.h"

#include "../src/GrassPlant/GrassPlant.h"
#include "../src/GrassFactory/GrassFactory.h"

#include "../src/SucculentPlant/SucculentPlant.h"   
#include "../src/SucculentFactory/SucculentFactory.h"

#include "../src/PlantDataFactory/PlantDataFactory.h"

#include <iostream>

TEST_SUITE("Factory Pattern Test") {
    TEST_CASE("FlowerFactory Test") {
        PlantDataFactory::initializeFactory();

        Plant* flowerPrototype1 = new FlowerPlant("F_Proto_1", "Flower Prototype 1", PlantDataFactory::getPlantData("FlowerPlant"));
        Plant* flowerPrototype2 = new FlowerPlant("F_Proto_2", "Flower Prototype 2", PlantDataFactory::getPlantData("FlowerPlant"));
        Plant* flowerPrototype3 = new FlowerPlant("F_Proto_3", "Flower Prototype 3", PlantDataFactory::getPlantData("FlowerPlant"));

        PlantFactory* flowerFactory = new FlowerFactory();

        flowerFactory->addPlantPrototype(flowerPrototype1);
        flowerFactory->addPlantPrototype(flowerPrototype2);
        flowerFactory->addPlantPrototype(flowerPrototype3);

        Plant* clonedFlower = flowerFactory->createPlant("Flower Prototype 2");

        CHECK(clonedFlower->getName() == "Flower Prototype 2");
        CHECK(clonedFlower->getStateName() == "Seedling");
        CHECK(clonedFlower->getSpeciesName() == flowerPrototype2->getSpeciesName());
        CHECK(clonedFlower->getWaterNeededForNextState() == flowerPrototype2->getWaterNeededForNextState());
        CHECK(clonedFlower->getFertilizerNeededForNextState() == flowerPrototype2->getFertilizerNeededForNextState());
        CHECK(clonedFlower->getWaterInterval() == flowerPrototype2->getWaterInterval());
        CHECK(clonedFlower->getFertilizerInterval() == flowerPrototype2->getFertilizerInterval());
        CHECK(clonedFlower->getWaterDeathTime() == flowerPrototype2->getWaterDeathTime());
        CHECK(clonedFlower->getFertilizerDeathTime() == flowerPrototype2->getFertilizerDeathTime());
        CHECK(clonedFlower->getId() == "clone");

        delete flowerFactory;

        delete clonedFlower;
    }

    TEST_CASE("TreeFactory Test") {
        PlantDataFactory::initializeFactory();

        Plant* treePrototype1 = new TreePlant("F_Proto_1", "Tree Prototype 1", PlantDataFactory::getPlantData("TreePlant"));
        Plant* treePrototype2 = new TreePlant("F_Proto_2", "Tree Prototype 2", PlantDataFactory::getPlantData("TreePlant"));
        Plant* treePrototype3 = new TreePlant("F_Proto_3", "Tree Prototype 3", PlantDataFactory::getPlantData("TreePlant"));

        PlantFactory* treeFactory = new FlowerFactory();

        treeFactory->addPlantPrototype(treePrototype1);
        treeFactory->addPlantPrototype(treePrototype2);
        treeFactory->addPlantPrototype(treePrototype3);

        Plant* clonedTree = treeFactory->createPlant("Tree Prototype 2");

        CHECK(clonedTree->getName() == "Tree Prototype 2");
        CHECK(clonedTree->getStateName() == "Seedling");
        CHECK(clonedTree->getSpeciesName() == treePrototype2->getSpeciesName());
        CHECK(clonedTree->getWaterNeededForNextState() == treePrototype2->getWaterNeededForNextState());
        CHECK(clonedTree->getFertilizerNeededForNextState() == treePrototype2->getFertilizerNeededForNextState());
        CHECK(clonedTree->getWaterInterval() == treePrototype2->getWaterInterval());
        CHECK(clonedTree->getFertilizerInterval() == treePrototype2->getFertilizerInterval());
        CHECK(clonedTree->getWaterDeathTime() == treePrototype2->getWaterDeathTime());
        CHECK(clonedTree->getFertilizerDeathTime() == treePrototype2->getFertilizerDeathTime());
        CHECK(clonedTree->getId() == "clone");

        delete treeFactory;

        delete clonedTree;
    }

    TEST_CASE("GrassFactory Test") {
        PlantDataFactory::initializeFactory();

        Plant* grassPrototype1 = new GrassPlant("F_Proto_1", "Grass Prototype 1", PlantDataFactory::getPlantData("GrassPlant"));
        Plant* grassPrototype2 = new GrassPlant("F_Proto_2", "Grass Prototype 2", PlantDataFactory::getPlantData("GrassPlant"));
        Plant* grassPrototype3 = new GrassPlant("F_Proto_3", "Grass Prototype 3", PlantDataFactory::getPlantData("GrassPlant"));

        PlantFactory* grassFactory = new FlowerFactory();

        grassFactory->addPlantPrototype(grassPrototype1);
        grassFactory->addPlantPrototype(grassPrototype2);
        grassFactory->addPlantPrototype(grassPrototype3);

        Plant* clonedGrass = grassFactory->createPlant("Grass Prototype 2");

        CHECK(clonedGrass->getName() == "Grass Prototype 2");
        CHECK(clonedGrass->getStateName() == "Seedling");
        CHECK(clonedGrass->getSpeciesName() == grassPrototype2->getSpeciesName());
        CHECK(clonedGrass->getWaterNeededForNextState() == grassPrototype2->getWaterNeededForNextState());
        CHECK(clonedGrass->getFertilizerNeededForNextState() == grassPrototype2->getFertilizerNeededForNextState());
        CHECK(clonedGrass->getWaterInterval() == grassPrototype2->getWaterInterval());
        CHECK(clonedGrass->getFertilizerInterval() == grassPrototype2->getFertilizerInterval());
        CHECK(clonedGrass->getWaterDeathTime() == grassPrototype2->getWaterDeathTime());
        CHECK(clonedGrass->getFertilizerDeathTime() == grassPrototype2->getFertilizerDeathTime());
        CHECK(clonedGrass->getId() == "clone");

        delete grassFactory;

        delete clonedGrass;
    }

    TEST_CASE("HerbFactory Test") {
        PlantDataFactory::initializeFactory();

        Plant* herbPrototype1 = new HerbPlant("F_Proto_1", "Herb Prototype 1", PlantDataFactory::getPlantData("HerbPlant"));
        Plant* herbPrototype2 = new HerbPlant("F_Proto_2", "Herb Prototype 2", PlantDataFactory::getPlantData("HerbPlant"));
        Plant* herbPrototype3 = new HerbPlant("F_Proto_3", "Herb Prototype 3", PlantDataFactory::getPlantData("HerbPlant"));

        PlantFactory* herbFactory = new FlowerFactory();

        herbFactory->addPlantPrototype(herbPrototype1);
        herbFactory->addPlantPrototype(herbPrototype2);
        herbFactory->addPlantPrototype(herbPrototype3);

        Plant* clonedHerb = herbFactory->createPlant("Herb Prototype 2");

        CHECK(clonedHerb->getName() == "Herb Prototype 2");
        CHECK(clonedHerb->getStateName() == "Seedling");
        CHECK(clonedHerb->getSpeciesName() == herbPrototype2->getSpeciesName());
        CHECK(clonedHerb->getWaterNeededForNextState() == herbPrototype2->getWaterNeededForNextState());
        CHECK(clonedHerb->getFertilizerNeededForNextState() == herbPrototype2->getFertilizerNeededForNextState());
        CHECK(clonedHerb->getWaterInterval() == herbPrototype2->getWaterInterval());
        CHECK(clonedHerb->getFertilizerInterval() == herbPrototype2->getFertilizerInterval());
        CHECK(clonedHerb->getWaterDeathTime() == herbPrototype2->getWaterDeathTime());
        CHECK(clonedHerb->getFertilizerDeathTime() == herbPrototype2->getFertilizerDeathTime());
        CHECK(clonedHerb->getId() == "clone");

        delete herbFactory;

        delete clonedHerb;
    }

    TEST_CASE("SucculentFactory Test") {
        PlantDataFactory::initializeFactory();

        Plant* succulentPrototype1 = new SucculentPlant("F_Proto_1", "Succulent Prototype 1", PlantDataFactory::getPlantData("SucculentPlant"));
        Plant* succulentPrototype2 = new SucculentPlant("F_Proto_2", "Succulent Prototype 2", PlantDataFactory::getPlantData("SucculentPlant"));
        Plant* succulentPrototype3 = new SucculentPlant("F_Proto_3", "Succulent Prototype 3", PlantDataFactory::getPlantData("SucculentPlant"));

        PlantFactory* succulentFactory = new FlowerFactory();

        succulentFactory->addPlantPrototype(succulentPrototype1);
        succulentFactory->addPlantPrototype(succulentPrototype2);
        succulentFactory->addPlantPrototype(succulentPrototype3);

        Plant* clonedSucculent = succulentFactory->createPlant("Succulent Prototype 2");

        CHECK(clonedSucculent->getName() == "Succulent Prototype 2");
        CHECK(clonedSucculent->getStateName() == "Seedling");
        CHECK(clonedSucculent->getSpeciesName() == succulentPrototype2->getSpeciesName());
        CHECK(clonedSucculent->getWaterNeededForNextState() == succulentPrototype2->getWaterNeededForNextState());
        CHECK(clonedSucculent->getFertilizerNeededForNextState() == succulentPrototype2->getFertilizerNeededForNextState());
        CHECK(clonedSucculent->getWaterInterval() == succulentPrototype2->getWaterInterval());
        CHECK(clonedSucculent->getFertilizerInterval() == succulentPrototype2->getFertilizerInterval());
        CHECK(clonedSucculent->getWaterDeathTime() == succulentPrototype2->getWaterDeathTime());
        CHECK(clonedSucculent->getFertilizerDeathTime() == succulentPrototype2->getFertilizerDeathTime());
        CHECK(clonedSucculent->getId() == "clone");

        delete succulentFactory;

        delete clonedSucculent;
    }
}