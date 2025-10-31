#ifndef STANDARDDELIVERY_H
#define STANDARDDELIVERY_H

#include "../Delivery/DeliveryStrategy.h"

class StandardDelivery : public DeliveryStrategy {
public:
    std::string deliver(Order o) override;
};

#endif
