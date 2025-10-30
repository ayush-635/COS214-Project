#ifndef CONCRETESPACEBUILDER_H
#define CONCRETESPACEBUILDER_H

#include "SpaceBuilder.h"

class ConcreteSpaceBuilder : public SpaceBuilder {
public:
    void addDefault();
    PlantSpace* build();
    
    ConcreteSpaceBuilder();
};

#endif
