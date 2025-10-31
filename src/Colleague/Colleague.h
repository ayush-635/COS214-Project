#ifndef COLLEAGUE_H
#define COLLEAGUE_H
#include <string>
#include "../Mediator/Mediator.h"

class Mediator;

class Colleague {

protected:
	Mediator* mediator;

public:
	Colleague();
	virtual std::string receiveAdvice();
	void setMediator(Mediator* m);
	virtual ~Colleague();
	Colleague(Mediator* m);
	
	Mediator* getMediator() const;
};

#endif
