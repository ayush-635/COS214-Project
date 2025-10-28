#include "Sales.h"
#include <iostream>

void Sales::tick() {
    std::cout << "Sales tick\n";
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
