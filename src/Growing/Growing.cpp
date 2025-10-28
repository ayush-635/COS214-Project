#include "Growing.h"
#include "../Plant/Plant.h"
#include <iostream>

void Growing::handle(Plant* plant) {
    if (canProgress(plant)) {
        plant->setState(std::make_unique<Mature>());
        std::cout << "🌿 " << plant->getName() << " grew from Growing to Mature!\n";
    }
}

bool Growing::canProgress(Plant* plant) {
    return plant->getWaterReceived() >= plant->getWaterNeededForNextState() * 2 &&
           plant->getFertilizerReceived() >= plant->getFertilizerNeededForNextState() * 2;
}