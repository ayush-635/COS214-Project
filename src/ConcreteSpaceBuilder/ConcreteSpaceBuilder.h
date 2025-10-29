#ifndef CONCRETESPACEBUILDER_H
#define CONCRETESPACEBUILDER_H

class ConcreteSpaceBuilder : SpaceBuilder {

public:
	PlantSpace* space;

	void addDefault();

	PlantSpace* build();

	ConcreteSpaceBuilder();
};

#endif
