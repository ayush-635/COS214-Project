#ifndef ORDER_H
#define ORDER_H

#include <list>
using namespace std;

class OrderItem;
class DeliveryStrategy;

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
