#ifndef INVENTORYOBSERVER_H
#define INVENTORYOBSERVER_H

#include <map>
#include <ostream>
#include "../Observer/Observer.h"

class Plant;
//class Inventory;

class InventoryObserver : public Observer {

private:
	std::map<Plant*, int> stock;
public:
	InventoryObserver() {};
	virtual void onStockChange(Plant* plant);
	void printStock(std::ostream& os) const;
	virtual ~InventoryObserver() {};
};

#endif
