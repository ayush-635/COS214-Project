#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include "../Colleague/Colleague.h"

class StaffMember : public Colleague {


public:
	virtual ~StaffMember() {};

	void doDuty();

	virtual void tick() = 0;

	virtual void receivePreference() = 0;

	virtual void browse() = 0;

	virtual void sendAdvice() = 0;
};

#endif
