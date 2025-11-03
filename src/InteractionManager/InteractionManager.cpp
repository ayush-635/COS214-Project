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
    // Handle random purchase requests
    if(msg.find("RANDOM_PURCHASE:") != std::string::npos){
        int numPlants = std::stoi(msg.substr(16));
        for(Colleague* c : list){
            Sales* sales = dynamic_cast<Sales*>(c);
            if(sales){
                std::string result = sales->handlePurchase(numPlants);
                std::cout << result << std::endl;
                break;
            }
        }
    } 
    // Handle new stock notifications
    else if(msg.find("NEW_STOCK:") != std::string::npos){
        std::string plantName = msg.substr(10);
        notifyAllCustomers(plantName + " is now available!");
    }
    // Handle advice from sales back to customer
    else if(msg.find("ADVICE:") != std::string::npos){
        std::string advice = msg.substr(7);
        // Find the customer who made the request and send them the advice
        for(Colleague* c : list){
            Customer* customer = dynamic_cast<Customer*>(c);
            if(customer){
                customer->storeAdvice(advice);
                std::cout << "Sales: " << advice << std::endl;
                break; // Send to first customer (most recent)
            }
        }
    }
    // Handle customer preferences (not PURCHASE_REQUEST)
    else if(msg != "PURCHASE_REQUEST"){
        // This is a customer preference - forward to sales staff
        for(Colleague* c : list){
            Sales* sales = dynamic_cast<Sales*>(c);
            if(sales){
                sales->receivePreference(msg);
                break; // Let first available sales staff handle it
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