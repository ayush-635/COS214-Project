#include "InteractionManager.h"
InteractionManager* InteractionManager::onlyInstance=0;
void InteractionManager::notifyAllCustomers(const std::string& message) {
    for(Colleague* c : list){
        Customer* customer = dynamic_cast<Customer*>(c);
        if(customer){
            customer->storeAdvice("Stock Update: " + message);
            std::cout << "Notified customer about: " << message << std::endl;
        }
    }
}

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
    } else if(msg.find("NEW_STOCK:")!=std::string::npos){
        std::string plantName = msg.substr(10);
        notifyAllCustomers(plantName + " is now available!");
    } else if(msg!="PURCHASE_REQUEST"){
        for(Colleague* c : list){
            Sales* sales = dynamic_cast<Sales*>(c);
            if(sales){
                sales->receivePreference(msg);
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

InteractionManager *InteractionManager::getInstance()
{
    static InteractionManager instance;
    return &instance;
}

InteractionManager::InteractionManager() {
}
