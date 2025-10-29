#include "Gardner.h"
#include <iostream>

void Gardner::tick(int time) {
    std::cout << "Sales tick +" << time << " Ticks spent alive: " << TimeSpent <<std::endl;
}

void Gardner::receivePreference() {
    std::cout << "Gardner receivePreference\n";
}

void Gardner::browse() {
    std::cout << "Gardner browse\n";
}

void Gardner::sendAdvice() {
    std::cout << "Gardner sendAdvice\n";
}
