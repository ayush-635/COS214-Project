#ifndef CONCRETESPACEBUILDER_H
#define CONCRETESPACEBUILDER_H

#include "../Builder/SpaceBuilder.h"

class ConcreteSpaceBuilder : public SpaceBuilder {
public:
    string addDefault();
    PlantSpace* build();
    
    ConcreteSpaceBuilder();
};

#endif
