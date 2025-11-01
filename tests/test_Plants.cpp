#include "doctest.h"
#include "../src/FlowerPlant/FlowerPlant.h"
#include "../src/TreePlant/TreePlant.h"
#include "../src/HerbPlant/HerbPlant.h"
#include "../src/GrassPlant/GrassPlant.h"
#include "../src/SucculentPlant/SucculentPlant.h"
#include "../src/PlantDataFactory/PlantDataFactory.h"

TEST_SUITE("Plant Type Tests") {


    TEST_CASE("FlowerPlant Creation") {

        PlantDataFactory::initializeFactory();
        auto data = PlantDataFactory::getPlantData("FlowerPlant");
        
        FlowerPlant flower("F1", "Rose", data);
        CHECK(flower.getName() == "Rose");
        CHECK(flower.getSpeciesName() == "FlowerPlant");
        CHECK(flower.getStateName() == "Seedling");


    }
    
    TEST_CASE("Different Plant Types Have Different Requirements") {

        PlantDataFactory::initializeFactory();
        
        auto flowerData = PlantDataFactory::getPlantData("FlowerPlant");
        auto treeData = PlantDataFactory::getPlantData("TreePlant");
        auto succulentData = PlantDataFactory::getPlantData("SucculentPlant");
        
        CHECK(flowerData->getWaterInterval() != treeData->getWaterInterval());
        CHECK(succulentData->getWaterDeathTime() > flowerData->getWaterDeathTime());
    }
    
    TEST_CASE("Plant Water and Fertilizer Tracking") {

        auto data = std::make_shared<PlantData>("Test", 3, 2, 5, 5, 10, 10);
        FlowerPlant plant("F1", "Test Flower", data);
        
        CHECK(plant.getWaterReceived() == 0);
        CHECK(plant.getFertilizerReceived() == 0);
        
        plant.water();
        plant.fertilize();
        
        CHECK(plant.getWaterReceived() == 1);
        CHECK(plant.getFertilizerReceived() == 1);

    }
    
    TEST_CASE("All Plant Types Can Be Created") {

        PlantDataFactory::initializeFactory();
        
        auto flowerData = PlantDataFactory::getPlantData("FlowerPlant");
        auto treeData = PlantDataFactory::getPlantData("TreePlant");
        auto herbData = PlantDataFactory::getPlantData("HerbPlant");
        auto grassData = PlantDataFactory::getPlantData("GrassPlant");
        auto succulentData = PlantDataFactory::getPlantData("SucculentPlant");
        
        CHECK_NOTHROW(FlowerPlant("F1", "Flower", flowerData));
        CHECK_NOTHROW(TreePlant("T1", "Tree", treeData));
        CHECK_NOTHROW(HerbPlant("H1", "Herb", herbData));
        CHECK_NOTHROW(GrassPlant("G1", "Grass", grassData));
        CHECK_NOTHROW(SucculentPlant("S1", "Succulent", succulentData));

        
    }
}