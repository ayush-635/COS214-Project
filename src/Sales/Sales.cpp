// ../src/Sales/Sales.cpp
#include "Sales.h"
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include "../PlantData/PlantData.h"
#include "../Mediator/Mediator.h"
#include <iostream>
#include <cstdlib>
#include <map>

void Sales::tick(int time) {
    std::cout << "Sales tick +" << time
              << " Ticks spent alive: " << totalTime() << std::endl;
}

// In YOUR Inventory there is no "getAllPlantNames()", so we will
// just try a few known names that we (will) add in main.
static const char* CANDIDATE_NAMES[] = {
    "Rose",
    "Lily",
    "Aloe",
    "Fern",
    "Succulent"
};
static const int NUM_CANDIDATES = sizeof(CANDIDATE_NAMES)/sizeof(CANDIDATE_NAMES[0]);

std::string Sales::findMatchingPlant(bool outside,
                                     bool lowLight,
                                     bool lowWater,
                                     bool brightColour,
                                     bool lowCare)
{
    Inventory* inv = Inventory::getInstance();
    std::vector<std::string> matchingPlants;

    // Use candidate names instead of getAllPlantNames()
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        std::string plantName = CANDIDATE_NAMES[i];
        Plant* plant = inv->getPrototype(plantName);
        if(!plant) continue;

        std::shared_ptr<PlantData> data = plant->getPlantData();
        if(!data) continue;
        
        bool matches = true;
        
        if (outside && !data->isOutside()) matches = false;
        if (lowLight && !data->isLowLight()) matches = false; 
        if (lowWater && !data->isLowWater()) matches = false;
        if (brightColour && !data->isBrightColour()) matches = false;
        if (lowCare && !data->isLowCare()) matches = false;

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
        // Fallback: your Mediator is only forward-declared, so we just print for now
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

    std::string advice = findMatchingPlant(needsOutside,
                                           needsLowLight,
                                           needsLowWater,
                                           needsBrightColor,
                                           needsLowCare);
    sendAdvice(advice);
}

std::string Sales::handlePurchase(int numPlants) {
    // Since we don't have getAllPlantNames, just pick from candidates
    Inventory* inv = Inventory::getInstance();
    std::string ret;
    ret = "Sales staff processing purchase of " + std::to_string(numPlants) + " plant(s)\n";

    int purchased = 0;
    for (int i = 0; i < numPlants && purchased < numPlants; ++i) {
        for (int c = 0; c < NUM_CANDIDATES; ++c) {
            std::string name = CANDIDATE_NAMES[c];
            if (inv->trySell(name, 1)) {
                ret += "Sold: " + name + "\n";
                purchased++;
                break;
            }
        }
    }

    if (purchased > 0) {
        ret += "Purchase completed! Sold " + std::to_string(purchased) + " plant(s).\n";
    } else {
        ret += "Sorry, no plants available for purchase at this time.\n";
    }

    return ret;
}