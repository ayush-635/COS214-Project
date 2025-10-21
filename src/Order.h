#ifndef ORDER_H
#define ORDER_H

class Order {

private:
	list<OrderItem*> items;
	DeliveryStrategy* delivery;

public:
	void addItem();

	double total();

	Order();
};

#endif
