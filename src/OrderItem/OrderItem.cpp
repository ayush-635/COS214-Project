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
