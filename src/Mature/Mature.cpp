#include "Mature.h"
#include "src/Plant/Plant.h"
#include <iostream>

void Mature::handle(Plant* plant) {
    if (canProgress(plant)) {
        plant->setState(std::make_unique<ReadyToSell>());
        std::cout << "🌳 " << plant->getName() << " is now ReadyToSell!\n";
    }
}

bool Mature::canProgress(Plant* plant) {
    return plant->getWaterReceived() >= plant->getWaterNeededForNextState() * 3 &&
           plant->getFertilizerReceived() >= plant->getFertilizerNeededForNextState() * 3;
}