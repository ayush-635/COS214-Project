#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <vector>


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
	std::vector<std::string> getAllPlantNames() const;
};

#endif
