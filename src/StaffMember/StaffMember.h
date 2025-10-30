#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H
#include "../Colleague/Colleague.h"
#include "../src/Colleague/Colleague.h"
#include "../src/Duty/Duty.h"
#include "../src/PlantableArea/PlantableArea.h"

class StaffMember : public Colleague {

	protected:
    Duty* currentDuty;          
    

public:

	StaffMember();
	
	void doDuty();

	void tick();

	

	void browse();

<<<<<<< HEAD
	
=======
	void sendAdvice();

	 void assignDuty(Duty* duty);

	 
>>>>>>> origin/feature/plantcarecommands-wateringstrategy
};

#endif
