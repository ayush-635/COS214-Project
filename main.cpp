#include "src/Game/Game.h"
#include "src/Plant/Plant.h"
#include "src/PlantData/PlantData.h"
#include "src/PlantDataFactory/PlantDataFactory.h"
#include "src/FlowerPlant/FlowerPlant.h"
#include "src/TreePlant/TreePlant.h"
#include "src/HerbPlant/HerbPlant.h"
#include "src/GrassPlant/GrassPlant.h"
#include "src/SucculentPlant/SucculentPlant.h"
#include "src/Seedling/Seedling.h"
#include "src/Growing/Growing.h"
#include "src/Mature/Mature.h"
#include "src/ReadyToSell/ReadyToSell.h"
#include "src/Dead/Dead.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "src/PlantFactory/PlantFactory.h"
#include "src/SucculentFactory/SucculentFactory.h"
#include "src/FlowerFactory/FlowerFactory.h"

int main() {
    Plant* flowerPlant = new FlowerPlant("F001", "Rose", PlantDataFactory::getPlantData("FlowerPlant"));
    Plant* flowerClone = flowerPlant->clone();
    delete flowerPlant;
    delete flowerClone;

    Plant* herbPlant = new HerbPlant("H001", "Garlic", PlantDataFactory::getPlantData("HerbPlant"));
    Plant* herbClone = herbPlant->clone();
    delete herbPlant;
    delete herbClone;

    Plant* treePlant = new TreePlant("F001", "Rose", PlantDataFactory::getPlantData("TreePlant"));
    Plant* treeClone = treePlant->clone();
    delete treePlant;
    delete treeClone;

    Plant* grassPlant = new GrassPlant("F001", "Rose", PlantDataFactory::getPlantData("GrassPlant"));
    Plant* grassClone = grassPlant->clone();
    delete grassPlant;
    delete grassClone;

    Plant* succulentPlant = new SucculentPlant("F001", "Rose", PlantDataFactory::getPlantData("SucculentPlant"));
    Plant* succulentClone = succulentPlant->clone();
    delete succulentPlant;
    delete succulentClone;
    
    return 0;
}
