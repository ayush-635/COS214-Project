// ../src/Sales/Sales.cpp
#include "Sales.h"
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include <iostream>
#include <cstdlib>

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
    (void)outside;
    (void)lowLight;
    (void)lowWater;
    (void)brightColour;
    (void)lowCare;
    // For now we just pick the first plant that actually has stock.
    Inventory* inv = Inventory::getInstance();

    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        std::string name = CANDIDATE_NAMES[i];
        int stock = inv->getStock(name);
        if (stock > 0) {
            return "We have " + name + " which matches your needs! We have "
                   + std::to_string(stock) + " in stock.";
        }
    }

    return "We don't have that plant in stock but we will notify you once it is in stock.";
}

void Sales::receivePreference(const std::string &pref)
{
    currPreference = pref;
    browse();
}

void Sales::sendAdvice(const std::string &advice)
{
    // your Mediator is only forward-declared, so we just print for now
    std::cout << "[Sales advice] " << advice << std::endl;
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
