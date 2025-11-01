#ifndef EXPRESSDELIVERY_H
#define EXPRESSDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

class ExpressDelivery : public DeliveryStrategy {
public:
    void deliver(Order o) override;
};

#endif
