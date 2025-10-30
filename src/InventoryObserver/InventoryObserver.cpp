#include "InventoryObserver.h"
#include <iostream>
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"

void InventoryObserver::onStockChange(Plant* plant) {
	//not done, waiting on singleton
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

	stock[plant] = current;

	std::cout <<"InventoryObserver: Stock changed for plant: " << plant->getName() << " (@" << plant << ") -> count = " << current << std::endl;
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