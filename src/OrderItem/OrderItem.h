#ifndef ORDERITEM_H
#define ORDERITEM_H
#include <string>
#include <sstream>
#include "../Pot/Pot.h"
using namespace std;

class OrderItem {
private:
	
	double unitPrice;
	int qty;
    Pot* pot;

public:
	std::string name;
	double subtotal();
	OrderItem();

	std::string getInfo();

    void addPot();
    bool hasPot() const { return pot != nullptr; }
    Pot* getPot() const { return pot; }

	OrderItem(std::string name, double price, int qty);
};

#endif

