#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {


public:
	virtual void onSotckChange(Plant* plant) = 0;
};

#endif
