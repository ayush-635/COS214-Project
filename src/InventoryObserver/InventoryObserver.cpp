#include "InventoryObserver.h"
#include <iostream>
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include "../InteractionManager/InteractionManager.h"

void InventoryObserver::onStockChange(Plant* plant) {
	if(!plant) {
		return;
	}

	Inventory* inv = Inventory::getInstance();
	int current = 0;
	if (inv){
		current = inv->getStock(plant->getName());
	} else {
		current = -1;
	}

	int previousStock = stock[plant];
	stock[plant] = current;

	std::cout <<"InventoryObserver: Stock changed for plant: " << plant->getName() << " (@" << plant << ") -> count = " << current << std::endl;
    
	if (previousStock == 0 && current > 0) {
        notifyCustomersOfNewStock(plant->getName());
    }
}

void InventoryObserver::printStock(std::ostream& os) const {
	os << "InventoryObserver stock cache (" << stock.size() << " entries): \n";
	for(auto it = stock.begin(); it != stock.end(); ++it){
		Plant* plant = it->first;
		int count = it->second;

		if (plant){
			os << " " << plant->getName() << " [" << plant << "] -> " << count << "\n";
		}else{
			os << "NULL plant pointer -> " << count << "\n";
		}
	}
}

void InventoryObserver::notifyCustomersOfNewStock(const std::string& plantName) {
    
    std::cout << "NEW_STOCK_ALERT: " << plantName << " is now in stock!\n";

    InteractionManager* mediator = InteractionManager::getInstance();
    mediator->notifyAllCustomers("NEW_STOCK:" + plantName);
}