#include "InventoryObserver.h"
#include <iostream>

void InventoryObserver::onStockChange(Plant* plant) {
	//not done, waiting on singleton
	if(!plant) {
		return;
	}

	stock[plant] = -1;
	std::cout << "InventoryObserver: Stock changed for plant at " << plant << std::endl;
}

void InventoryObserver::printStock(std::ostream& os) const {
	os << "InventoryObserver stock cache (" << stock.size() << " entries): \n";
	std::map<Plant*, int>::const_iterator it = stock.begin();
	for(;it != stock.end(); ++it){
		os << " Plant@ " << it->first << "->" << it->second << "\n";
	}
}