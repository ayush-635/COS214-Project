#include "doctest.h"
#include "../src/Game/Game.h"
#include "../src/FlowerPlant/FlowerPlant.h"
#include "../src/PlantDataFactory/PlantDataFactory.h"

TEST_SUITE("Game Manager Tests") {
    TEST_CASE("Game Singleton Pattern") {
        Game* game1 = Game::getInstance();
        Game* game2 = Game::getInstance();
        
        CHECK(game1 == game2); // Should be same instance

    }
    
    TEST_CASE("Add Plants to Game") {

        Game* game = Game::getInstance();
        PlantDataFactory::initializeFactory();
        
        auto data = PlantDataFactory::getPlantData("FlowerPlant");
        game->addPlant(std::make_unique<FlowerPlant>("TEST_F1", "Test Rose", data));
        
        // Should be able to retrieve plant

        auto plant = game->getPlant("TEST_F1");
        CHECK(plant != nullptr);
        CHECK(plant->getName() == "Test Rose");
        
        // Clean up
        game->removePlant("TEST_F1");

    }
    
    TEST_CASE("Game Update All Plants") {

        Game* game = Game::getInstance();
        PlantDataFactory::initializeFactory();
        
        // Use unique ID to avoid conflicts
        auto data = PlantDataFactory::getPlantData("FlowerPlant");
        game->addPlant(std::make_unique<FlowerPlant>("TEST_UPDATE", "Test Rose", data));
        


        // Update should not crash and should progress plant state
        CHECK_NOTHROW(game->update());
        
        // Clean up
        game->removePlant("TEST_UPDATE");
    }
    
    TEST_CASE("Water and Fertilize Plants via Game") {
        Game* game = Game::getInstance();
        PlantDataFactory::initializeFactory();
        
        // Use unique ID to avoid conflicts
        auto data = PlantDataFactory::getPlantData("FlowerPlant");
        game->addPlant(std::make_unique<FlowerPlant>("TEST_CARE", "Care Rose", data));
        
        game->waterPlant("TEST_CARE");
        game->fertilizePlant("TEST_CARE");
        
        auto plant = game->getPlant("TEST_CARE");
        CHECK(plant->getWaterReceived() == 1);
        CHECK(plant->getFertilizerReceived() == 1);
        
        // Clean up
        game->removePlant("TEST_CARE");
    }
    
    TEST_CASE("Remove Plants from Game") {
        Game* game = Game::getInstance();
        PlantDataFactory::initializeFactory();
        
        auto data = PlantDataFactory::getPlantData("FlowerPlant");
        game->addPlant(std::make_unique<FlowerPlant>("TEST_REMOVE", "Remove Rose", data));
        
        // Plant should exist
        auto plant = game->getPlant("TEST_REMOVE");
        CHECK(plant != nullptr);
        
        // Remove plant
        game->removePlant("TEST_REMOVE");
        
        // Plant should no longer exist
        plant = game->getPlant("TEST_REMOVE");
        CHECK(plant == nullptr);
    }
    
    TEST_CASE("Game Handles Non-Existent Plants") {

        
        Game* game = Game::getInstance();
        
        // Should handle non-existent plants gracefully
        CHECK_NOTHROW(game->waterPlant("NON_EXISTENT"));
        CHECK_NOTHROW(game->fertilizePlant("NON_EXISTENT"));
        CHECK_NOTHROW(game->removePlant("NON_EXISTENT"));
        
        auto plant = game->getPlant("NON_EXISTENT");
        CHECK(plant == nullptr);
    }
}