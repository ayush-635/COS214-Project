#include "Dying.h"
#include "../Plant/Plant.h"
#include <iostream>

Dying::Dying(const std::string& prevState) : previousState(prevState) {}

void Dying::handle(Plant* plant) {
    // Recovery is handled in Plant::update() and Plant::water()/fertilize(), here is just death progress
    
    if (canProgress(plant)) {
        plant->setState(std::make_unique<Dead>());
        std::cout << "💀 " << plant->getName() << " died from neglect!\n";
    }
}

bool Dying::canProgress(Plant* plant) {
    return plant->getTicksWithoutWater() >= plant->getWaterDeathTime() || 
           plant->getTicksWithoutFertilizer() >= plant->getFertilizerDeathTime();
}