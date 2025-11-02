#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Plant;

/**
 * @class Subject
 * @brief Base class for Observer pattern subjects.
 * Classes that inherit from Subject can attach observers and notify them of stock changes.
 * Observer can register themselves to be notified when stock changes occur.
 * All can be notified of stock changes via notifyStockChange.
 */
class Subject {
private:
	/// @brief List of attached observers (Observer pointers)
	std::vector<Observer*> observers;

public:
	/**
	 * @brief Attach an observer to the subject
	 * If the pointer is non-null, adds it to the list of observers.
	 * @param observer Pointer to the Observer to attach
	 */
	void attach(Observer* observer);

	/// @brief Default constructor
	Subject() {};
	/// @brief Virtual destructor
	virtual ~Subject() {};

protected:
	/**
	 * @brief Notify all attached observers of a stock change for a given plant
	 * Calls onStockChange(plant) on each attached observer.
	 * @param plant Pointer to the Plant whose stock has changed
	 */
	void notifyStockChange(Plant* plant);
};

#endif
