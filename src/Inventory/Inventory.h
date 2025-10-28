#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include "../Subject/Subject.h"

class Plant;
class PlantFactory;

class Inventory : public Subject {

private:
	static Inventory* instance;
	std::map<Plant*, int> stock;

	Inventory();
	~Inventory() {};

public:
	static Inventory* getInstance();

	void addStockType(PlantFactory* factory,const std::string name,const std::string idealSeason);

	int getStock(const std::string name) const;

	void updateStock(const std::string& name, int count);
};

#endif
