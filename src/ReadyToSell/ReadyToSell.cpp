#include "ReadyToSell.h"
#include "src/Plant/Plant.h"

void ReadyToSell::handle(Plant* /*plant*/) {
    // Plants stay in this state until sold
}

bool ReadyToSell::canProgress(Plant* /*plant*/) {
    return false;
}