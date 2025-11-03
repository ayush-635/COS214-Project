#ifndef INVENTORYOBSERVER_H
#define INVENTORYOBSERVER_H

#include <map>
#include <ostream>
#include "../Observer/Observer.h"

class Plant;
//class Inventory;

/**
 * @class InventoryObserver
 * @brief Observer that monitors stock changes in the Inventory.
 * When stock levels change, it updates its internal cache and notifies customers if new stock arrives.
 * This observer keeps a small cache of stock levels for plants it is interested in.
 * - key: Plant* (pointer to the plant)
 * - value: int (current stock level)
 * adds notification functionality when stock goes from 0 to >0.
 */
class InventoryObserver : public Observer {

private:
	/// @brief Cache of stock levels for monitored plants
	std::map<Plant*, int> stock;
public:
	/// @brief Constructor
	InventoryObserver() {};

	/**
	 * @brief Handle stock change notifications from the Inventory
	 * Typical flow:
	 * - Asks the Inventory for the current stock level of the plant
	 * - Updates its cache
	 * - Prints the change
	 * - Notifies customers if stock went from 0 to >0
	 * @param plant Pointer to the Plant whose stock has changed
	 */
	virtual void onStockChange(Plant* plant);

	/**
	 * @brief Print the current stock cache to the given output stream
	 * @param os The output stream to print to
	 */
	void printStock(std::ostream& os) const;

	/// @brief Destructor
	virtual ~InventoryObserver() {};

	/**
	 * @brief Notify customers that new stock of a plant is available
	 * @param plantName The name of the plant that is now in stock
	 */
	void notifyCustomersOfNewStock(const std::string& plantName);
};

#endif
