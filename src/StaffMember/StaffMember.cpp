#include "StaffMember.h"

StaffMember::StaffMember() : TimeSpent(0){}

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

virtual void browse(){
}

virtual void receivePreference(const std::string& pref){
	(void)pref;
}

virtual void sendAdvice(const std::string& advice){
	if(mediator){
		mediator->sendAdvice(advice, this);
	}
}

virtual void tick(int time){
	(void)time;
}