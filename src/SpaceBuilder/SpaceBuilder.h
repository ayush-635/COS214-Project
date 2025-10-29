#ifndef SPACEBUILDER_H
#define SPACEBUILDER_H

class SpaceBuilder {

public:
	PlantSpace* space;

	void setSize(int width, int length);

	void reset();

	void setName(int name);

	void addSubSpace();

	PlantSpace* build();

	SpaceBuilder();
};

#endif
