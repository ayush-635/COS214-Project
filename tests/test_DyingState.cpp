#include "doctest.h"
#include "../src/Plant/Plant.h"
#include "../src/PlantData/PlantData.h"
#include "../src/FlowerPlant/FlowerPlant.h"

TEST_SUITE("Dying State Tests") {
    TEST_CASE("Plant Enters Dying State When Needing Both Water and Fertilizer") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 3, 10, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Simulate enough ticks to need both water and fertilizer
        for (int i = 0; i < 4; i++) {
            plant.update();
        }
        
        CHECK(plant.needsWater() == true);
        CHECK(plant.needsFertilizer() == true);
        CHECK(plant.isDying() == true);
    }
    
    TEST_CASE("Plant Recovers From Dying State When Watered And Fertilized") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 3, 10, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Make plant enter dying state
        for (int i = 0; i < 4; i++) {
            plant.update();
        }
        CHECK(plant.isDying() == true);
        
        // Water AND fertilize the plant - should recover immediately
        plant.water();
        plant.fertilize();
        
        CHECK(plant.isDying() == false);
        CHECK(plant.getStateName() == "Seedling");
    }
    
    TEST_CASE("Plant Stays In Dying State When Only One Need Is Met") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 3, 10, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Make plant enter dying state
        for (int i = 0; i < 4; i++) {
            plant.update();
        }
        CHECK(plant.isDying() == true);
        
        // Only water the plant - should stay in dying state
        plant.water();
        
        CHECK(plant.isDying() == true);
        
        // Only fertilize the plant - should leave dying state  
        plant.fertilize();
        
        CHECK(plant.isDying() == false);
    }
    
    TEST_CASE("Plant Recovers From Dying When Both Needs Are Met") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 3, 10, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Make plant enter dying state
        for (int i = 0; i < 4; i++) {
            plant.update();
        }
        CHECK(plant.isDying() == true);
        
        // Water and fertilize the plant - should recover
        plant.water();
        plant.fertilize();
        
        CHECK(plant.isDying() == false);
    }
    
    TEST_CASE("Plant Dies If Not Cared For While Dying") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 3, 6, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Make plant enter dying state
        for (int i = 0; i < 4; i++) {
            plant.update();
        }
        CHECK(plant.isDying() == true);
        
        // Continue without care until death
        for (int i = 0; i < 3; i++) {
            plant.update();
        }
        
        CHECK(plant.isDead() == true);
    }
    
    TEST_CASE("Plant Remembers Previous State Before Dying") {
        auto data = std::make_shared<PlantData>("Test", 2, 1, 3, 3, 10, 10);
        FlowerPlant plant("T1", "Test Plant", data);
        
        // Progress to Growing state first
        plant.water();
        plant.water();
        plant.fertilize();
        plant.update(); // Should transition to Growing
        
        CHECK(plant.getStateName() == "Growing");
        
        // Make plant enter dying state
        for (int i = 0; i < 4; i++) {
            plant.update();
        }
        CHECK(plant.isDying() == true);
        
        // Recover by providing both water and fertilizer - should go back to Growing state
        plant.water();
        plant.fertilize();
        
        CHECK(plant.getStateName() == "Growing");
    }
}