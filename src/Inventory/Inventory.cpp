#include "Inventory.h"

Inventory* Inventory::instance = 0;

Inventory::Inventory() {

}

Inventory* Inventory::getInstance(){
	// TODO - implement Inventory::getInstance
	if (!instance){
		instance = new Inventory();
	}
	return instance;
}

void Inventory::addStockType(PlantFactory* factory,const std::string name,const std::string idealSeason) {
	// TODO - implement Inventory::addStockType
	throw "Not yet implemented";
}

int Inventory::getStock(const std::string name) const{
	// TODO - implement Inventory::getStock
	throw "Not yet implemented";
}

void Inventory::updateStock(const std::string& name, int count) {
	// TODO - implement Inventory::updateStock
	throw "Not yet implemented";
}
