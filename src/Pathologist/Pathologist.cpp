#include "Pathologist.h"
#include <iostream>

void Pathologist::tick(int time) {
    std::cout << "Sales tick +" << time << " Ticks spent alive: " << totalTime() <<std::endl;
}

void Pathologist::receivePreference() {
    std::cout << "Pathologist receivePreference\n";
}

void Pathologist::browse() {
    std::cout << "Pathologist browse\n";
}

void Pathologist::sendAdvice() {
    std::cout << "Pathologist sendAdvice\n";
}
