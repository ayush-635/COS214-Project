#ifndef DELIVERYSTRATEGY_H
#define DELIVERYSTRATEGY_H

#include <iostream>
#include <string>

class Order;

class DeliveryStrategy {
public:
    virtual void deliver(Order o) = 0;
    virtual ~DeliveryStrategy() {}
    
    DeliveryStrategy();
};

#endif
