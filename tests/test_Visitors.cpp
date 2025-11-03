#include "doctest.h"
#include "../src/HealthCheckVisitor/HealthCheckVisitor.h"
#include "../src/FlowerPlant/FlowerPlant.h"
#include "../src/PlantDataFactory/PlantDataFactory.h"

TEST_SUITE("Visitor Pattern Tests") {
    TEST_CASE("HealthCheckVisitor Creation") {

        HealthCheckVisitor visitor;
        // Should compile and be usable
        SUBCASE("Visitor can be instantiated") {
            CHECK(true);


        }
    }
    
    TEST_CASE("Plants Accept Visitors") {

        PlantDataFactory::initializeFactory();
        auto data = PlantDataFactory::getPlantData("FlowerPlant");
        FlowerPlant plant("F1", "Rose", data);
        HealthCheckVisitor visitor;
        
        // Should not crash when plant accepts visitor
        CHECK_NOTHROW(plant.accept(visitor));


    }
    
    TEST_CASE("Visitor Collects Reports") {
        
        PlantDataFactory::initializeFactory();
        auto data = PlantDataFactory::getPlantData("FlowerPlant");
        FlowerPlant plant("F1", "Rose", data);
        HealthCheckVisitor visitor;
        
        plant.accept(visitor);
        
        // Should be able to print report without crashing
        CHECK_NOTHROW(visitor.printReport());
        
        // Should be able to clear reports
        CHECK_NOTHROW(visitor.clearReports());


    }
}