#ifndef COLLEAGUE_H
#define COLLEAGUE_H
#include <string>
#include "../Mediator/Mediator.h"

class Mediator;

class Mediator;

class Colleague {

protected:
	Mediator* mediator;

public:
	Colleague();
	virtual std::string receiveAdvice();
	void setMediator(Mediator* m);
	virtual ~Colleague();
	explicit Colleague(Mediator* m = 0);
	
	Mediator* getMediator() const;
};

#endif
