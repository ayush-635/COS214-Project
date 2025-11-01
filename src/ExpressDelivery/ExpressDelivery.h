#ifndef EXPRESSDELIVERY_H
#define EXPRESSDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

class ExpressDelivery : public DeliveryStrategy {
public:
    void deliver(const Order& order) override;
    double getDeliveryCost() const override { return 150.0; }
    std::string getDeliveryType() const override { return "Express Delivery"; }
};

#endif