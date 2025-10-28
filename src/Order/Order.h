#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <list>
class DeliveryStrategy;
class OrderItem;

class Order {

private:
	std::list<OrderItem*> items;
	//DeliveryStrategy* delivery;

public:
	void addItem(OrderItem* item);

	double total();
	std::string getOrder();

	//Order(DeliveryStrategy* d);
	Order();
};

#endif
