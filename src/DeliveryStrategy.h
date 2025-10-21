#ifndef DELIVERYSTRATEGY_H
#define DELIVERYSTRATEGY_H

class DeliveryStrategy {


public:
	virtual void deliver(Order o) = 0;

	DeliveryStrategy();
};

#endif
