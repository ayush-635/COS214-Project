#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <vector>


#include <map>
#include <string>
#include "../Subject/Subject.h"
#include "../InventoryObserver/InventoryObserver.h"

class Plant;
class PlantFactory;

class Inventory : public Subject {

private:
	static Inventory* instance;
	std::map<std::string, int> qtyByName;
	std::map<std::string, Plant*> protoByName;
	std::map<std::string, std::string> idealSeasonByName;
	PlantFactory* factory;

	Inventory();
	~Inventory();

	Inventory(const Inventory&);
	Inventory& operator=(const Inventory&);

	Plant* ensurePrototype(const std::string& name);
public:
	static Inventory* getInstance();

	void setFactory(PlantFactory* f);

	void addStockType(PlantFactory* f, const std::string name, const std::string idealSeason);

	std::vector<std::string> getAllPlantNames() const;
	int getStock(const std::string& name) const;

	void updateStock(const std::string& name, int count);

	bool trySell(const std::string& name, int qty);

	void restock(const std::string& name, int qty);

	Plant* getPrototype(const std::string& name) const;

	std::string getIdealSeason(const std::string& name) const;
};

#endif
