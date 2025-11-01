#ifndef PICKUPDELIVERY_H
#define PICKUPDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

class PickupDelivery : public DeliveryStrategy {
public:
    void deliver(const Order& order) override;
    double getDeliveryCost() const override { return 0.0; }
    std::string getDeliveryType() const override { return "Customer Pickup"; }
};

#endif