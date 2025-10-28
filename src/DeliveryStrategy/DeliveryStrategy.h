#ifndef DELIVERYSTRATEGY_H
#define DELIVERYSTRATEGY_H

class Order;

class DeliveryStrategy {


public:
	virtual void deliver(Order o)=0;

	virtual ~DeliveryStrategy()=default;
};

#endif
