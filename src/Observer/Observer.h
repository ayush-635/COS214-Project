#ifndef OBSERVER_H
#define OBSERVER_H

class Plant;

/**
 * @class Observer
 * @brief Abstract base class for observers in the Observer pattern.
 * Observers must implement the onStockChange method to handle notifications of stock changes.
 */
class Observer {


public:
	/// @brief Virtual destructor
	virtual ~Observer() = default;
	/**
	 * @brief Handle stock change notifications from the Inventory
	 * @param plant Pointer to the Plant whose stock has changed
	 */
	virtual void onStockChange(Plant* plant) = 0;
};

#endif
