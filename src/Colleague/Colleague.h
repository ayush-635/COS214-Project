#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class Mediator;

class Colleague {

protected:
	Mediator* mediator;

public:
	explicit Colleague(Mediator* m = 0);
	virtual ~Colleague();

	void setMediator(Mediator* m);
	
	Mediator* getMediator() const;
};

#endif
