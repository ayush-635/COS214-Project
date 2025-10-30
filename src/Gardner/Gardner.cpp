// ../src/Gardner/Gardner.cpp
#include "Gardner.h"
#include "../Inventory/Inventory.h"
#include <iostream>

void Gardner::tick(int time) {
    std::cout << "Gardner tick +" << time
              << " Ticks spent alive: " << totalTime() << std::endl;
}

void Gardner::receivePreference(const std::string& pref) {
    currPreference = pref;
    browse();
}

void Gardner::browse() {
    if (currPreference.empty()) {
        return;
    }

    // same parsing as Sales
    bool needsOutside     = (currPreference.find("outside") != std::string::npos);
    bool needsLowLight    = (currPreference.find("without much sunlight") != std::string::npos);
    bool needsLowWater    = (currPreference.find("not need much water") != std::string::npos);
    bool needsBrightColor = (currPreference.find("bright coloured") != std::string::npos);
    bool needsLowCare     = (currPreference.find("not need much attention") != std::string::npos);

    // since Inventory has no getAllPlantNames, just look at known ones
    Inventory* inv = Inventory::getInstance();
    const char* names[] = { "Rose", "Lily", "Aloe", "Fern", "Succulent" };
    const int N = sizeof(names)/sizeof(names[0]);

    for (int i = 0; i < N; ++i) {
        std::string name = names[i];
        if (inv->getStock(name) > 0) {
            sendAdvice("Gardner: You can use " + name + " — it should be fine.");
            return;
        }
    }

    sendAdvice("Gardner: I don't have a good suggestion right now.");
}

void Gardner::sendAdvice(const std::string& advice) {
    // print instead of mediator->notify(...)
    std::cout << "[Gardner advice] " << advice << std::endl;
}
