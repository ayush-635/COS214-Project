#include "Cashier.h"
#include <iostream>

void Cashier::tick() {
    std::cout << "Cashier tick\n";
}

void Cashier::receivePreference() {
    std::cout << "Cashier receivePreference\n";
}

void Cashier::browse() {
    std::cout << "Cashier browse\n";
}

void Cashier::sendAdvice() {
    std::cout << "Cashier sendAdvice\n";
}

bool Cashier::checkStockLevel(Plant* plant) {
	//after inventory is complete this will be completed, temporarily returns false
	return false;
}

void Cashier::requestNewStock(Plant* plant, int qty) {
	//after Observer/Invetory is completed this can be completed
	std::cout << "Cashier called requestNewStock function\n";
}
