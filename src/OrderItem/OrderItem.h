#ifndef ORDERITEM_H
#define ORDERITEM_H
#include <string>
#include <sstream>

class OrderItem {

private:
	
	double unitPrice;
	int qty;

public:
	std::string name;
	double subtotal();

	std::string getInfo();

	OrderItem(std::string name, double price, int qty);
};

#endif
