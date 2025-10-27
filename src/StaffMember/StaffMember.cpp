#include "StaffMember.h"
#include "Duty.h"
#include "PlantableArea.h"


StaffMember::StaffMember() : currentDuty(nullptr), currentArea(nullptr){}

void StaffMember::doDuty() {
	if (!currentDuty || !currentArea) return;

        currentDuty->executeDuty(currentArea);
    
}

void StaffMember::assignDuty(Duty* duty, PlantableArea* area) {
        currentDuty = duty;
        currentArea = area;
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
