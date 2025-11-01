#ifndef PICKUPDELIVERY_H
#define PICKUPDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

class PickupDelivery : public DeliveryStrategy {
public:
    void deliver(Order o) override;
};

#endif
