#include "Sales.h"
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include "../PlantData/PlantData.h"
#include "../Mediator/Mediator.h"
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <memory>


void Sales::tick(int time) {
    std::cout << "Sales tick +" << time
              << " Ticks spent alive: " << totalTime() << std::endl;
}

std::string Sales::findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare){
    Inventory* inv = Inventory::getInstance();
    std::vector<std::string> matchingPlants;

    std::vector<std::string> allPlants = inv->getAllPlantNames();
    for(const std::string& plantName : allPlants) {
        Plant* plant = inv->getPrototype(plantName);
        if(!plant) continue;
        std::shared_ptr<PlantData> data = plant->getPlantData();
        if(!data) continue;

        bool matches = true;
        if(outside && !data->isOutside()) matches = false;
        if(lowLight && !data->isLowLight()) matches = false;
        if(lowWater && !data->isLowWater()) matches = false;
        if(brightColour && !data->isBrightColour()) matches = false;
        if(lowCare && !data->isLowCare()) matches = false;

        if(matches) {
            int stock = inv->getStock(plantName);
            if(stock > 0) {
                matchingPlants.push_back(plantName);
            }
        }
    }

    if(!matchingPlants.empty()) {
        std::string plantName = matchingPlants[0];
        int stock = inv->getStock(plantName);
        return "We have " + plantName + " which matches your needs. We have " + std::to_string(stock) + " in stock.";
    }
    
    return "We don't have that plant in stock but we will plant it and notify you once in stock.";
}

void Sales::receivePreference(const std::string &pref)
{
    currPreference = pref;
    browse();
}

void Sales::sendAdvice(const std::string &advice) {
    if(mediator) {
        mediator->notify(this, "ADVICE:" + advice);
    } else {
        std::cout << "[Sales advice] " << advice << std::endl;
    }
}

Sales::Sales() : currPreference("")
{
}

void Sales::browse() {
    if (currPreference.empty()) {
        return;
    }

    bool needsOutside     = (currPreference.find("outside") != std::string::npos);
    bool needsLowLight    = (currPreference.find("without much sunlight") != std::string::npos);
    bool needsLowWater    = (currPreference.find("not need much water") != std::string::npos);
    bool needsBrightColor = (currPreference.find("bright coloured") != std::string::npos);
    bool needsLowCare     = (currPreference.find("not need much attention") != std::string::npos);

    std::string advice = findMatchingPlant(needsOutside, needsLowLight, needsLowWater, needsBrightColor, needsLowCare);
    sendAdvice(advice);
}

std::string Sales::handlePurchase(int numPlants) {
    Inventory* inv = Inventory::getInstance();
    std::string ret;
    ret = "Sales staff processing purchase of " + std::to_string(numPlants) + " plant(s)\n";
    std::vector<std::string> allNames = inv->getAllPlantNames();

    int purchased = 0;
    while (purchased < numPlants) {
        bool soldSomethingThisPass = false;

        for (const std::string& name : allNames) {
            if (purchased >= numPlants) break;

            if (inv->trySell(name, 1)) {
                ret += "Sold: " + name + "\n";
                purchased++;
                soldSomethingThisPass = true;
            }
        }

        if (!soldSomethingThisPass) {
            break;
        }
    }

    if (purchased > 0) {
        ret += "Purchase completed! Sold " + std::to_string(purchased) + " plant(s).\n";
    } else {
        ret += "Sorry, no plants available for purchase at this time.\n";
    }

    return ret;
}