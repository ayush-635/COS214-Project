#include "OrderItem.h"

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
