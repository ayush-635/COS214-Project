#ifndef EXPRESSDELIVERY_H
#define EXPRESSDELIVERY_H

#include "../Delivery/DeliveryStrategy.h"

class ExpressDelivery : public DeliveryStrategy {
public:
    std::string deliver(Order o) override;
};

#endif
