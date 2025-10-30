#ifndef INTERACTIONMANAGER_H
#define INTERACTIONMANAGER_H
#include <string>
#include "../Mediator/Mediator.h"
#include <vector>
#include "../Sales/Sales.h"
#include "../Customer/Customer.h"

class InteractionManager : public Mediator {

public:
	std::vector<Colleague*> list;

	void notify(Colleague* colleague, std::string msg);
	void addColleague(Colleague* c);
	void remColleague(Colleague* c);

	InteractionManager();
};

#endif
