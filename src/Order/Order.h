#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <list>
#include "DeliveryStrategy.h"
#include "OrderItem.h" 

class Order {

private:
	std::list<OrderItem*> items;
	DeliveryStrategy* delivery;

public:
	void addItem(OrderItem* item);

	double total();
	std::string getOrder();

	Order(DeliveryStrategy* d);
};

#endif
