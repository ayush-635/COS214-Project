#include "Seedling.h"
#include "src/Plant/Plant.h"
#include <iostream>

void Seedling::handle(Plant* plant) {
    if (canProgress(plant)) {
        plant->setState(std::make_unique<Growing>());
        std::cout << "🌱 " << plant->getName() << " grew from Seedling to Growing!\n";
    }
}

bool Seedling::canProgress(Plant* plant) {
    return plant->getWaterReceived() >= plant->getWaterNeededForNextState() &&
           plant->getFertilizerReceived() >= plant->getFertilizerNeededForNextState();
}