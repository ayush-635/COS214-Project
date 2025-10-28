#ifndef INTERACTIONMANAGER_H
#define INTERACTIONMANAGER_H

class InteractionManager : Mediator {

public:
	vector<Colleague*> list;

	void notify(Colleague* colleague);

	InteractionManager();
};

#endif
