#include "Colleague.h"

Colleague::Colleague() : mediator(nullptr){}

std::string Colleague::receiveAdvice()
{
    return "";
}

void Colleague::setMediator(Mediator *m)
{
	mediator = m;
}

Colleague::~Colleague()
{
}
