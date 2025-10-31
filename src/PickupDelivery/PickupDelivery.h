#ifndef PICKUPDELIVERY_H
#define PICKUPDELIVERY_H

#include "../Delivery/DeliveryStrategy.h"

class PickupDelivery : public DeliveryStrategy {
public:
    std::string deliver(Order o) override;
};

#endif

