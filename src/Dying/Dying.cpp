#include "Dying.h"
#include "src/Plant/Plant.h"
#include <iostream>

Dying::Dying(const std::string& prevState) : previousState(prevState) {}

void Dying::handle(Plant* plant) {
    // Recovery is now handled immediately in water()/fertilize() methods
    
    if (canProgress(plant)) {
        plant->setState(std::make_unique<Dead>());
        std::cout << "💀 " << plant->getName() << " died from neglect!\n";
    }
}

bool Dying::canProgress(Plant* plant) {
    return plant->getTicksWithoutWater() >= plant->getWaterDeathTime() || 
           plant->getTicksWithoutFertilizer() >= plant->getFertilizerDeathTime();
}