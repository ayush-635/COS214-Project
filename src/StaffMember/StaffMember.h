#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include "Colleague.h"
#include "Duty.h"
#include "PlantableArea.h"

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

	 void assignDuty(Duty* duty, PlantableArea* area);

	 
};

#endif
