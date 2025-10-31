#include "OrderItem.h"
#include <iostream>

OrderItem::OrderItem() {
    name = "Plant Item";
    unitPrice = 150.0;  // Default price
    qty = 1;
}

double OrderItem::subtotal() {
	return qty * unitPrice;
}

std::string OrderItem::getInfo() {
	std::stringstream oss;
	oss<<"Name: "<<name<<"\nQuantity: "<<qty<<"\nUnit Price: "<<unitPrice<<"\nSubtotal: "<<subtotal()<<"\n";
	return oss.str();
}

OrderItem::OrderItem(std::string name, double price, int qty) {
	this->name = name;
	unitPrice = price;
	this->qty = qty;
}


void OrderItem::addPot() {

    delete pot;
    
    struct PotType {
        std::string color;
        double price;
    };
    
    PotType potTypes[] = {
        {"Red", 25.0},
        {"Blue", 30.0},
        {"Green", 35.0}
    };
    
    int randomIndex = rand() % 3; 
    
    pot = new Pot(potTypes[randomIndex].color, 1, potTypes[randomIndex].price);
}

