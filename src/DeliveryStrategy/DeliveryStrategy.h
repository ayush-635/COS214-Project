#ifndef DELIVERYSTRATEGY_H
#define DELIVERYSTRATEGY_H

#include <iostream>
#include <string>

class Order;

class DeliveryStrategy {
public:
    virtual void deliver(const Order& order) = 0;
    virtual double getDeliveryCost() const = 0;
    virtual std::string getDeliveryType() const = 0;
    virtual ~DeliveryStrategy() {}
    
    DeliveryStrategy();
};

#endif