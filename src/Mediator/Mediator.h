#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <string>

class Colleague;

class Mediator {

public:
	virtual void notify(Colleague* colleague, std::string msg) = 0;

	Mediator();
	virtual ~Mediator();
};

#endif
