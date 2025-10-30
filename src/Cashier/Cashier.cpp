#include "Cashier.h"
#include <iostream>

void Cashier::tick(int time) {
    std::cout << "Sales Cashier +" << time << " Ticks spent alive: " << totalTime() <<std::endl;
}

void Cashier::receivePreference() {
    currPreference = pref;
    if(pref.rfind("CHECK: ", 0) == 0){
        std::string plantName = pref.substr(6);
        int stock = inv->getStock(plantName);
        sendAdvice("Stock level for " + plantName + " is " + std::to_string(stock));
        return;
    }

    if(pref.rfind("BUY:", 0) == 0){
        std::stringstream ss(pref.substr(4));
        std::string qty;
        std::string plantName;
        std::getline(ss, plantName, ':');
        std::getline(ss, qty, ':');
        int quantity = std::stoi(qty);

        bool ok = inv->trySell(plantName, quantity);
        if(ok){
            sendAdvice("Successfully sold " + std::to_string(quantity) + " of " + plantName);
        } else {
            sendAdvice("Failed to sell " + std::to_string(quantity) + " of " + plantName + ". Not enough stock.");
        }
        return;
    }
    sendAdvice("Cashier received Illegal preference: " + pref);
}

void Cashier::sendAdvice(const std::string& message) {
    if(mediator){
        mediator->notify(this, message);
    }
}

bool Cashier::checkStockLevel(Plant* plant) {
	//after inventory is complete this will be completed, temporarily returns false
	return false;
}

void Cashier::requestNewStock(Plant* plant, int qty) {
	//after Observer/Invetory is completed this can be completed
	std::cout << "Cashier called requestNewStock function\n";
}
