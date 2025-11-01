#ifndef STANDARDDELIVERY_H
#define STANDARDDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

class StandardDelivery : public DeliveryStrategy {
public:
    void deliver(Order o) override;
};

#endif
