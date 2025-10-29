#include "InteractionManager.h"

void InteractionManager::notify(Colleague* colleague, std::string msg) {
	colleague->
}

void InteractionManager::addColleague(Colleague *c)
{
	list.push_back(c);
}

void InteractionManager::remColleague(Colleague *c)
{
	for(std::vector<Colleague*>::iterator it = list.begin(); it!=list.end(); ++it){
		if(*it == c){
			list.erase(it);
			return;
		}
	}
}

InteractionManager::InteractionManager() {
}
