#ifndef INVENTORYOBSERVER_H
#define INVENTORYOBSERVER_H

class InventoryObserver : Observer {

public:
	std::map<Plant*, null> stock;

	void onSotckChange(Plant* plant);
};

#endif
