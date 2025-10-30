#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H


#include "../src/Colleague/Colleague.h"
class Duty;



class StaffMember : public Colleague {

	protected:
    Duty* currentDuty;          
    

public:

	StaffMember();
	
	void doDuty();

	void tick();

	void receivePreference();

	void browse();

	void sendAdvice();

	 void assignDuty(Duty* duty);

	 
};

#endif
