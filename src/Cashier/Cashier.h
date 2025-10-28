#ifndef CASHIER_H
#define CASHIER_H

#include "../StaffMember/StaffMember.h"

class Plant;

class Cashier : public StaffMember {
public:
	Cashier(){};
	virtual ~Cashier(){};

	virtual void tick();

    virtual void receivePreference();

    virtual void browse();
	
	virtual void sendAdvice();

	bool checkStockLevel(Plant* plant);

	void requestNewStock(Plant* plant, int qty);
};

#endif
