#include "Order.h"

void Order::addItem(OrderItem* item) {
	items.push_back(item);
}

double Order::total() {
	double sum=0;
	for(std::list<OrderItem*>::iterator it = items.begin(); it!=items.end(); ++it){
		sum+=(*it)->subtotal();
	}
	return sum;
}

std::string Order::getOrder()
{
    std::string ret="";
	for(std::list<OrderItem*>::iterator it = items.begin(); it!=items.end(); ++it){
		ret+=(*it)->name+"\n";
	}
	return ret;
}

Order::Order(DeliveryStrategy* d) {
	delivery = d;
}
