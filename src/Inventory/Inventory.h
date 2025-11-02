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

/**
 * @class Inventory
 * @brief Singleton class that manages the inventory of plants.
 * The inventory knows the following:
 * - How many seeds/units of a plant we have ('qtyByName')
 * - The prototype of each plant ('protoByName')
 * - The ideal season for each plant ('idealSeasonByName')
 *
 * It also acts as a Subject in the Observer pattern, when stock changes it notifies its observers (InventoryObservers).
 */

class Inventory : public Subject {

private:
	/// @brief The singleton instance of the Inventory
	static Inventory* instance;

	/// @brief The current stock levels of each plant
	std::map<std::string, int> qtyByName;

	/// @brief The prototype plants for each plant type
	std::map<std::string, Plant*> protoByName;

	/// @brief The ideal growing season for each plant type
	std::map<std::string, std::string> idealSeasonByName;

	/// @brief The PlantFactory used to create plant prototypes
	PlantFactory* factory;

	/**
	 * @brief Private constructor for the singleton Inventory class
	 */
	Inventory();
	/**
	 * @brief Destructor for the Inventory class
	 */
	~Inventory();

	/**
	 * @brief Disable copy constructor and assignment operator
	 */
	Inventory(const Inventory&);
	Inventory& operator=(const Inventory&);

	/**
	 * @brief Ensures that a prototype plant exists for the given name.
	 * If it does not exist, it uses the PlantFactory to create one.
	 * @param name The name of the plant
	 * @return A pointer to the prototype Plant
	 */
	Plant* ensurePrototype(const std::string& name);
public:
	/**
	 * @brief Get the singleton instance of the Inventory
	 * @return A pointer to the Inventory instance
	 */
	static Inventory* getInstance();

	/**
	 * @brief Set the PlantFactory for the Inventory
	 * @param f A pointer to the PlantFactory
	 */
	void setFactory(PlantFactory* f);

	/**
	 * @brief Add a new stock type to the inventory
	 * @param f A pointer to the PlantFactory
	 * @param name The name of the plant
	 * @param idealSeason The ideal growing season for the plant
	 */
	void addStockType(PlantFactory* f, const std::string name, const std::string idealSeason);

	/**
	 * @brief Get a list of all plant names in the inventory
	 * @return A vector of plant names
	 */
	std::vector<std::string> getAllPlantNames() const;

	/**
	 * @brief Get the current stock level for a given plant
	 * @param name The name of the plant
	 * @return The current stock level of the plant
	 */
	int getStock(const std::string& name) const;

	/**
	 * @brief Update the stock level for a given plant
	 * @param name The name of the plant
	 * @param count positive to increase stock, negative to decrease stock
	 */
	void updateStock(const std::string& name, int count);

	/**
	 * @brief Try to sell a given quantity of a plant
	 * @param name The name of the plant
	 * @param qty The quantity to sell
	 * @return True if the sale was successful, false otherwise
	 */
	bool trySell(const std::string& name, int qty);

	/**
	 * @brief Restock a given quantity of a plant
	 * @param name The name of the plant
	 * @param qty The quantity to restock
	 */
	void restock(const std::string& name, int qty);

	/**
	 * @brief Get the prototype plant for a given name
	 * @param name The name of the plant
	 * @return A pointer to the prototype Plant
	 */
	Plant* getPrototype(const std::string& name) const;

	/**
	 * @brief Get the ideal growing season for a given plant
	 * @param name The name of the plant
	 * @return The ideal growing season of the plant
	 */
	std::string getIdealSeason(const std::string& name) const;
};

#endif
