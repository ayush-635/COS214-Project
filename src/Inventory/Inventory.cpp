#include "Inventory.h"

Inventory::Inventory() {
	// TODO - implement Inventory::Inventory
	throw "Not yet implemented";
}

static Inventory* Inventory::getInstance() {
	// TODO - implement Inventory::getInstance
	throw "Not yet implemented";
}

void Inventory::addStockType(PlantFactory* factory, std::string name, std::string idealSeason) {
	// TODO - implement Inventory::addStockType
	throw "Not yet implemented";
}

int Inventory::getStock(std::string name) {
	// TODO - implement Inventory::getStock
	throw "Not yet implemented";
}

void Inventory::updateStock(int name_std::string, int count) {
	// TODO - implement Inventory::updateStock
	throw "Not yet implemented";
}

std::vector<std::string> Inventory::getAllPlantNames() const
{
    std::vector<std::string> names;
    for (auto& pair : protoByName) {
        names.push_back(pair.first);
    }
    return names;
}
