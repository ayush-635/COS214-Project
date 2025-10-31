#include "Dead.h"
#include "../Plant/Plant.h"

void Dead::handle(Plant* /*plant*/) {
    // Plant is dead
}

bool Dead::canProgress(Plant* /*plant*/) {
    return false;
}