#include "Dead.h"
#include "src/Plant/Plant.h"

void Dead::handle(Plant* /*plant*/) {
    // Plant is dead
}

bool Dead::canProgress(Plant* /*plant*/) {
    return false;
}