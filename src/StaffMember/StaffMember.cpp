#include "StaffMember.h"

void StaffMember::doDuty() {
	tick();
	browse();
	receivePreference();
	sendAdvice();
}