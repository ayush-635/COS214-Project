#include "StaffMember.h"


StaffMember::StaffMember() : Colleague(), TimeSpent(0){}
StaffMember::~StaffMember(){}

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
	receivePreference("");
	sendAdvice("");
}

void StaffMember::browse(){
}

void StaffMember::receivePreference(const std::string& /*pref*/){
}

void StaffMember::sendAdvice(const std::string& /*advice*/){
}

void StaffMember::tick(int /*time*/){
}