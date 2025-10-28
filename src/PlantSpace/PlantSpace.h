#ifndef PLANTSPACE_H
#define PLANTSPACE_H

class PlantSpace {

public:
	string name;
	vector<SpaceComponent*> subspaces;

	void addComponent();

	void removeComponent();
};

#endif
