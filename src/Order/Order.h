#ifndef ORDER_H
#define ORDER_H
#include "string"

class Order {

private:
	list<OrderItem*> items;
	DeliveryStrategy* delivery;

public:
	void addItem();

	double total();
	std::string getOrder();

	Order();
};

#endif
