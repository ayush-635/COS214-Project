#include "Colleague.h"

Colleague::Colleague() : mediator(nullptr){}

std::string Colleague::receiveAdvice()
{
    return "";
}

Colleague::Colleague(Mediator* m)
    : mediator(m) {
}

Colleague::~Colleague(){}

void Colleague::setMediator(Mediator* m){
	mediator = m;
}

Mediator* Colleague::getMediator() const {
	return mediator;
}
