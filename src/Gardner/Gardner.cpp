#include "Gardner.h"
#include "../Inventory/Inventory.h"
#include <iostream>
#include <vector> 
#include <memory>
#include "../Plant/Plant.h"
#include "../PlantData/PlantData.h"

void Gardner::tick(int time) {
    std::cout << "Gardner tick +" << time
              << " Ticks spent alive: " << totalTime() << std::endl;
}

void Gardner::receivePreference(const std::string& pref) {
    currPreference = pref;
    browse();
}

void Gardner::browse() {
    if(currPreference.empty()) {
        sendAdvice("Gardner has no preference to browse.");
        return;
    }

    bool needsOutside = currPreference.find("outside") != std::string::npos;
    bool needsLowLight = currPreference.find("low light") != std::string::npos;
    bool needsLowWater = currPreference.find("low water") != std::string::npos;
    bool needsBrightColour = currPreference.find("bright colour") != std::string::npos;
    bool needsLowCare = currPreference.find("low care") != std::string::npos;

    Inventory* inv = Inventory::getInstance();
    if(!inv) {
        sendAdvice("Gardner: Inventory instance not available.");
        return;
    } 

    std::vector<std::string> allNames = inv->getAllPlantNames();
    for(const std::string& name : allNames) {
        if(inv->getStock(name) <= 0) {
            continue;
        }

        Plant* Proto = inv->getPrototype(name);
        if(!Proto) {
            continue;
        }

        std::shared_ptr<PlantData> dataPtr = Proto->getPlantData();
        if (!dataPtr) {
            continue;
        }
        PlantData* data = dataPtr.get();

        bool matches = true;
        if(needsOutside && !data->isOutside()) matches = false;
        if(needsLowLight && !data->isLowLight()) matches = false;
        if(needsLowWater && !data->isLowWater()) matches = false;
        if(needsBrightColour && !data->isBrightColour()) matches = false;
        if(needsLowCare && !data->isLowCare()) matches = false;

        if(matches) {
            sendAdvice("Gardner found a matching plant: " + name);
        }
    }

    sendAdvice("I couldn't find any plants matching your preferences.");
}

void Gardner::sendAdvice(const std::string& advice) {
    if(mediator) {
        mediator->notify(this, "ADVICE:" + advice);
    } else {
        std::cout << "[Gardner advice] " << advice << std::endl;
    }
}
