#ifndef OBSERVER_H
#define OBSERVER_H

class Plant;

class Observer {


public:
	virtual ~Observer() {};
	virtual void onStockChange(Plant* plant) = 0;
};

#endif
