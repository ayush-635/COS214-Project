#include "StaffMember.h"

StaffMember::StaffMember() : Colleague(0), TimeSpent(0){}

int StaffMember::totalTime() const{
	return TimeSpent;
}

void StaffMember::doDuty() {
	doDuty(1);
}

void StaffMember::addTime(int time){
	TimeSpent += time;
}

void StaffMember::doDuty(int time){
	addTime(time);
	tick(time);
	browse();
	receivePreference();
	sendAdvice();
}