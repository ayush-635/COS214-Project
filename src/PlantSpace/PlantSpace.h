#ifndef PLANTSPACE_H
#define PLANTSPACE_H

#include <string>
#include <vector>
using namespace std;

class SpaceComponent;

class PlantSpace {

public:
	string name;
	vector<SpaceComponent*> subspaces;

	void addComponent();

	void removeComponent();
};

#endif
