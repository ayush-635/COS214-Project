#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

class StaffMember : Colleague {


public:
	void doDuty();

	void tick();

	void receivePreference();

	void browse();

	void sendAdvice();
};

#endif
