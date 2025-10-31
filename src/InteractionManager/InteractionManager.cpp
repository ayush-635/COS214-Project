#include "InteractionManager.h"

void InteractionManager::notify(Colleague* colleague, std::string msg) {
	Customer* customer;
	if(msg.find("RANDOM_PURCHASE:")!=std::string::npos){
		int numPlants = std::stoi(msg.substr(16));
		for(Colleague* c : list){
			Sales* sales = dynamic_cast<Sales*>(c);
			if(sales){
				sales->handlePurchase(numPlants);
				break;
			}
		}
	} else if(msg!="PURCHASE_REQUEST"){
		for(Colleague* c : list){
			Sales* sales = dynamic_cast<Sales*>(c);
			if(sales){
				sales->receivePreference(msg);
			}
		}
	} else if (msg.find("ADVICE:") != std::string::npos) {
			for(Colleague* c : list) {
				Customer* customer = dynamic_cast<Customer*>(c);
				if(customer && c != colleague) {
					customer->storeAdvice(msg.substr(7));
				}
			}
		}
}

void InteractionManager::addColleague(Colleague *c)
{
	list.push_back(c);
	c->setMediator(this);
}

void InteractionManager::remColleague(Colleague *c)
{
	for(std::vector<Colleague*>::iterator it = list.begin(); it!=list.end(); ++it){
		if(*it == c){
			list.erase(it);
			return;
		}
	}
}

InteractionManager::InteractionManager() {
}
