#ifndef MEDIATOR_H
#define MEDIATOR_H

class Mediator {


public:
	virtual void notify(Colleague* colleague) = 0;

	Mediator();
};

#endif
