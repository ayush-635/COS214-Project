#include "Sales.h"
#include <iostream>

void Sales::tick(int time) {;
    std::cout << "Sales tick +" << time << " Ticks spent alive: " << totalTime() <<std::endl;
}

void Sales::receivePreference() {
    std::cout << "Sales receivePreference\n";
}

void Sales::browse() {
    std::cout << "Sales browse\n";
}

void Sales::sendAdvice() {
    std::cout << "Sales sendAdvice\n";
}
