#include "Customer.h"

bool Customer::requestSale(Plant* plant) {
	if(mediator){
		std::string msg = "PURCHASE_REQUEST";
		mediator->notify(this, msg);
		return true;
	}
	return false;
}

std::string Customer::purchaseRandomPlants()
{
	std::string msg="";
	int numPlants = (std::rand()%3)+1;
	if (mediator) {
		msg = "RANDOM_PURCHASE:" + std::to_string(numPlants);
		mediator->notify(this, msg);
	}
	return msg;
}

std::string Customer::sendPreference() {
	rand = (std::rand()%preferences.size())+1;
	std::string msg = preferences.find(rand)->second;
	if(mediator){
		mediator->notify(this, msg);
	}
	return "Customer: "+msg;
}

void Customer::storeAdvice(const std::string &advice)
{
	lastAdvice = advice;
}

std::string Customer::receiveAdvice() {
	return lastAdvice;
}

Customer::Customer() : lastAdvice(""), rand(0) {
	preferences[1] = "I want a plant for outside";
	preferences[2] = "I want a plant that can live inside without much sunlight";
	preferences[3] = "I want a plant that does not need much water";
	preferences[4] = "I want a bright coloured plant";
	preferences[5] = "I want a plant that does not need much attention";

	std::srand(std::time(nullptr));
}

