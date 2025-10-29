#ifndef COLLEAGUE_H
#define COLLEAGUE_H
#include <string>

class Mediator;

class Colleague {

protected:
	Mediator* mediator;

public:
	Colleague();
	virtual std::string receiveAdvice();
	void setMediator(Mediator* m);
	virtual ~Colleague();
};

#endif
