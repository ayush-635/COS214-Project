#include "Pathologist.h"
#include <iostream>

void Pathologist::tick() {
    std::cout << "Pathologist tick\n";
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
