#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest.h"
#include "../src/Duty/Duty.h"
#include "../src/PlantSeedCommand/PlantSeedCommand.h"
#include "../src/RemovePlantCommand/RemovePlantCommand.h"
#include "../src/GiveFertilizerCommand/GiveFertilizerCommand.h"
#include "../src/GiveMedicineCommand/GiveMedicineCommand.h"
#include "../src/WaterPlantCommand/WaterPlantCommand.h"
#include "../src/Plant/Plant.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include "../src/PlanterBox/PlanterBox.h"
#include "../src/WateringStrategy/WateringStrategy.h"
#include "../src/LightWateringStrategy/LightWateringStrategy.h"
#include "../src/IntermediateWateringStrategy/IntermediateWateringStrategy.h"
#include "../src/HeavyWateringStrategy/HeavyWateringStrategy.h"
#include <iostream>

TEST_CASE("PlantSeedCommand executes without crashing") {

    
    PlantDataFactory::initializeFactory();
    auto data = PlantDataFactory::getPlantData("FlowerPlant");
    FlowerPlant seed("F1", "Rose", data);
    PlanterBoxCollection row(0);
    PlanterBox* box1 = new PlanterBox();
    PlanterBox* box2 = new PlanterBox();
    row.add(box1);
    row.add(box2);
    PlantSeedCommand cmd(&row, &seed, 0);
    cmd.executeDuty();
    CHECK(box1->getPlants().size() == 1);
    CHECK(box1->getPlants()[0]->getName() == "Rose");
    CHECK(box2->getPlants().empty());
}


TEST_CASE("RemovePlantCommand executes without crashing") {
    PlantDataFactory::initializeFactory();
    auto data = PlantDataFactory::getPlantData("FlowerPlant");
    FlowerPlant seed("F1", "Tulip", data);
    PlanterBoxCollection row(0);
    PlanterBox* box1 = new PlanterBox();
    row.add(box1);
    box1->populate(&seed);
    RemovePlantCommand cmd(&row, &seed, 0);
    cmd.executeDuty();
    CHECK(box1->getPlants().empty());
}

TEST_CASE("GiveFertilizerCommand executes without crashing") {
   PlantDataFactory::initializeFactory();
    auto data = PlantDataFactory::getPlantData("FlowerPlant");
    FlowerPlant seed("F1", "Daisy", data);
    PlanterBoxCollection row(0);
    PlanterBox* box1 = new PlanterBox();
    row.add(box1);
    box1->populate(&seed);
    GiveFertilizerCommand cmd(&row, 3, 0);
    cmd.executeDuty();
    CHECK(seed.getFertilizerReceived() == 3);
    
}

TEST_CASE("GiveMedicineCommand executes without crashing") {
    PlantDataFactory::initializeFactory();
    auto data = PlantDataFactory::getPlantData("FlowerPlant");
    FlowerPlant seed("F1", "Lily", data);
    PlanterBoxCollection row(0);
    PlanterBox* box1 = new PlanterBox();
    row.add(box1);
    box1->populate(&seed);
    GiveMedicineCommand cmd(&row, 0);
    cmd.executeDuty();
    CHECK(!seed.isDead());
    
}

TEST_CASE("WaterPlantCommand executes without crashing with different strategies") {
    PlantDataFactory::initializeFactory();
    auto data = PlantDataFactory::getPlantData("FlowerPlant");
    FlowerPlant seed1("F1", "Orchid", data);
    FlowerPlant seed2("F2", "Sunflower", data);
    PlanterBoxCollection row(0);
    PlanterBox* box1 = new PlanterBox();
    row.add(box1);
    box1->populate(&seed1);
    box1->populate(&seed2);
    
    LightWateringStrategy light;
    IntermediateWateringStrategy intermediate;
    HeavyWateringStrategy heavy;

    WaterPlantCommand cmdLight(&row, &light, 0);
    cmdLight.executeDuty();
    CHECK(seed1.getWaterReceived() == 1);
    CHECK(seed2.getWaterReceived() == 1);

    WaterPlantCommand cmdIntermediate(&row, &intermediate, 0);
    cmdIntermediate.executeDuty();
    CHECK(seed1.getWaterReceived() == 1 + 3);
    CHECK(seed2.getWaterReceived() == 1 + 3);

    WaterPlantCommand cmdHeavy(&row, &heavy, 0);
    cmdHeavy.executeDuty();
    CHECK(seed1.getWaterReceived() == 1 + 3 + 5);
    CHECK(seed2.getWaterReceived() == 1 + 3 + 5);
}

