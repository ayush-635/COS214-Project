#ifndef STANDARDDELIVERY_H
#define STANDARDDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

class StandardDelivery : public DeliveryStrategy {
public:
    void deliver(const Order& order) override;
    double getDeliveryCost() const override { return 50.0; }
    std::string getDeliveryType() const override { return "Standard Delivery"; }
};

#endif