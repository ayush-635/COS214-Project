#include "../src/StaffMember/StaffMember.h



StaffMember::StaffMember() : currentDuty(nullptr) {}

void StaffMember::doDuty() {
	if (!currentDuty){ 
		
	std::cout<<"No Duty provided\n";
	return;

	
	}
        currentDuty->executeDuty();
    
}

void StaffMember::assignDuty(Duty* duty) {
        currentDuty = duty;
        
    }

void StaffMember::tick() {
	// TODO - implement StaffMember::tick
	throw "Not yet implemented";
}

void StaffMember::receivePreference() {
	// TODO - implement StaffMember::receivePreference
	throw "Not yet implemented";
}

void StaffMember::browse() {
	// TODO - implement StaffMember::browse
	throw "Not yet implemented";
}

void StaffMember::sendAdvice() {
	// TODO - implement StaffMember::sendAdvice
	throw "Not yet implemented";
}
