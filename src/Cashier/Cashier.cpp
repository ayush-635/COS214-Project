#include "Cashier.h"
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include <iostream>
#include <sstream>

void Cashier::tick(int time) {
    std::cout << "Cashier tick +" << time
              << " Ticks spent alive: " << totalTime() << std::endl;
}

void Cashier::receivePreference(const std::string& pref) {
    currPreference = pref;
    Inventory* inv = Inventory::getInstance();
    if (pref.rfind("CHECK:", 0) == 0) {
        std::string plantName = pref.substr(6);
        int stock = inv->getStock(plantName);
        sendAdvice("Stock level for " + plantName + " is " + std::to_string(stock));
        return;
    }

    if (pref.rfind("BUY:", 0) == 0) {
        std::stringstream ss(pref.substr(4));
        std::string plantName;
        std::string qtyStr;
        std::getline(ss, plantName, ':');
        std::getline(ss, qtyStr, ':');
        int qty = std::stoi(qtyStr);

        bool ok = inv->trySell(plantName, qty);
        if (ok) {
            sendAdvice("Successfully sold " + std::to_string(qty) + " of " + plantName);
        } else {
            sendAdvice("Failed to sell " + std::to_string(qty) + " of " + plantName + " (not enough stock)");
        }
        return;
    }

    sendAdvice("Cashier received illegal preference: " + pref);
}

void Cashier::sendAdvice(const std::string& message) {
    // print instead of mediator->notify(...)
    std::cout << "[Cashier advice] " << message << std::endl;
}

// keep these if you want to call them from main:
bool Cashier::checkStockLevel(Plant* plant) {
    if(!plant) return false;

    Inventory* inv = Inventory::getInstance();
    int stock = inv->getStock(plant->getName());
    std::cout << "Cashier checked stock level for" << plant->getName() << ": " << stock << std::endl;
    return stock > 0;
}

void Cashier::requestNewStock(Plant* plant, int qty) {
    if(!plant){
        std::cout << "Cashier requestNewStock called with null plant pointer." << std::endl;
        return;
    }

    if(qty <= 0){
        std::cout << "Cashier requestNewStock called with non-positive quantity: " << qty << std::endl;
        return;
    }

    std::string plantName = plant->getName();
    Inventory* inv = Inventory::getInstance();

    inv->updateStock(plantName, qty);
    std::cout << "Cashier requested new stock: " << qty << " of " << plantName << std::endl;
}
