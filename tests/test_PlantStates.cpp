#include "doctest.h"
#include "../src/Plant/Plant.h"
#include "../src/PlantData/PlantData.h"
#include "../src/PlantDataFactory/PlantDataFactory.h"
#include "../src/FlowerPlant/FlowerPlant.h"  // Add this include

TEST_SUITE("Plant State Tests") {
    TEST_CASE("Initial State is Seedling") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 5, 5, 10, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        CHECK(plant.getStateName() == "Seedling");
    }
    
    TEST_CASE("Seedling to Growing Transition") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 5, 5, 10, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Water and fertilize enough to progress
        plant.water();
        plant.water();
        plant.fertilize();
        
        plant.update(); // Should trigger state transition
        
        CHECK(plant.getStateName() == "Growing");
    }
    
    TEST_CASE("Plant Death from Thirst") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 10, 5, 20);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Simulate many updates without water
        for (int i = 0; i < 6; i++) {
            plant.update();
        }
        
        CHECK(plant.getStateName() == "Dead");
        CHECK(plant.isDead() == true);
    }
    
    TEST_CASE("Plant Needs Water Detection") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 10, 10, 20);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Initially shouldn't need water
        CHECK(plant.needsWater() == false);
        
        // Simulate enough ticks to need water
        for (int i = 0; i < 3; i++) {
            plant.update();
        }
        
        CHECK(plant.needsWater() == true);
    }
}