#ifndef SPACEBUILDER_H
#define SPACEBUILDER_H

#include <string>
using namespace std;

class PlantSpace;

class SpaceBuilder {
public:
    PlantSpace* space;

    void setSize(int width, int length);
    void reset();
    void setName(int name);
    void addSubSpace();
    PlantSpace* build();
    
    SpaceBuilder();
    virtual ~SpaceBuilder() {}
};

#endif
