#include "Dead.h"
#include "src/Plant/Plant.h"

void Dead::handle(Plant* plant) {
    // Dead plants don't do anything
}

bool Dead::canProgress(Plant* plant) {
    return false;
}