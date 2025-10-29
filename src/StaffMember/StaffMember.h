#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include "../Colleague/Colleague.h"

class StaffMember : public Colleague {
protected:
	void addTime(int time);
	int TimeSpent;
public:
	StaffMember();
	virtual ~StaffMember() {};

	void doDuty();
	void doDuty(int time);

	virtual void tick(int time) = 0;

	virtual void receivePreference() = 0;

	virtual void browse() = 0;

	virtual void sendAdvice() = 0;

	int totalTime() const;
};

#endif
