#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory : Subject {

private:
	Inventory instance;
	std::map<Plant*, null> stock;

	Inventory();

public:
	static Inventory* getInstance();

	void addStockType(PlantFactory* factory, std::string name, std::string idealSeason);

	int getStock(std::string name);

	void updateStock(int name_std::string, int count);
};

#endif
