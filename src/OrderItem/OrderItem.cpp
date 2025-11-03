#include "OrderItem.h"
#include <iostream>
#include <cstdlib>

OrderItem::OrderItem() {
    name = "Plant Item";
    unitPrice = 150.0;
    qty = 1;
    pot = nullptr;
}

OrderItem::OrderItem(std::string name, double price, int qty) {
    this->name = name;
    unitPrice = price;
    this->qty = qty;
    pot = nullptr;
}

OrderItem::~OrderItem() {
    if (pot) {
        delete pot;
    }
}

double OrderItem::subtotal() {
    double total = qty * unitPrice;
    if (pot) {
        total += pot->getPrice();
    }
    return total;
}

std::string OrderItem::getInfo() {
    std::stringstream oss;
    oss << "Name: " << name << "\n";
    oss << "Quantity: " << qty << "\n";
    oss << "Unit Price: R" << unitPrice << "\n";
    if (pot) {
        oss << "Pot: " << pot->getColour() << " pot (R" << pot->getPrice() << ")\n";
    }
    oss << "Subtotal: R" << subtotal() << "\n";
    return oss.str();
}

void OrderItem::addPot() {
    // Clean up existing pot if any
    if (pot) {
        delete pot;
        pot = nullptr;
    }
    
    struct PotType {
        std::string color;
        double price;
    };
    
    PotType potTypes[] = {
        {"Red", 25.0},
        {"Blue", 30.0},
        {"Green", 35.0},
        {"Terracotta", 20.0},
        {"White", 28.0}
    };
    
    int randomIndex = rand() % 5;
    pot = new Pot(potTypes[randomIndex].color, 1, potTypes[randomIndex].price);
}