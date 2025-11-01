#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Plant;

class Subject {

private:
	std::vector<Observer*> observers;

public:
	void attach(Observer* observer);

	Subject() {};
	virtual ~Subject() {};

protected:
	void notifyStockChange(Plant* plant);
};

#endif
