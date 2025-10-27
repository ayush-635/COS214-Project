#include "doctest.h"
#include "../src/PlantData/PlantData.h"
#include "../src/PlantDataFactory/PlantDataFactory.h"

TEST_SUITE("PlantData Tests") {
    TEST_CASE("PlantData Construction and Getters") {
        PlantData data("TestPlant", 2, 1, 3, 4, 5, 6);
        
        CHECK(data.getSpeciesName() == "TestPlant");
        CHECK(data.getWaterNeededForNextState() == 2);
        CHECK(data.getFertilizerNeededForNextState() == 1);
    }
    
    TEST_CASE("PlantDataFactory Returns Valid Objects") {
        PlantDataFactory::initializeFactory();
        
        // Test that we can get data for all expected types
        CHECK_NOTHROW(PlantDataFactory::getPlantData("FlowerPlant"));
        CHECK_NOTHROW(PlantDataFactory::getPlantData("TreePlant"));
        CHECK_NOTHROW(PlantDataFactory::getPlantData("HerbPlant"));
        CHECK_NOTHROW(PlantDataFactory::getPlantData("GrassPlant"));
        CHECK_NOTHROW(PlantDataFactory::getPlantData("SucculentPlant"));
        
        // Test that returned objects have correct data
        auto flower = PlantDataFactory::getPlantData("FlowerPlant");
        CHECK(flower->getSpeciesName() == "FlowerPlant");
        
        auto tree = PlantDataFactory::getPlantData("TreePlant");
        CHECK(tree->getSpeciesName() == "TreePlant");
    }
    
    TEST_CASE("PlantDataFactory Consistent Values") {
        PlantDataFactory::initializeFactory();
        
        auto data1 = PlantDataFactory::getPlantData("FlowerPlant");
        auto data2 = PlantDataFactory::getPlantData("FlowerPlant");
        
        // Test that values are consistent (flyweight pattern)
        CHECK(data1->getWaterNeededForNextState() == data2->getWaterNeededForNextState());
        CHECK(data1->getFertilizerNeededForNextState() == data2->getFertilizerNeededForNextState());
    }
}