#include "ReadyToSell.h"
#include "../Plant/Plant.h"

void ReadyToSell::handle(Plant* /*plant*/) {
    // Plants stay in this state until sold
}

bool ReadyToSell::canProgress(Plant* /*plant*/) {
    return false;
}