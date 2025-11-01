#ifndef SPACEBUILDER_H
#define SPACEBUILDER_H

#include <string>
using namespace std;
#include "../PlantableArea/PlantableArea.h"
#include "../PlanterBoxCollection/PlanterBoxCollection.h"


class SpaceBuilder {
protected:
    PlantableArea* space;
public:
    PlantableArea* build(){
        PlantableArea* result = space;
        space = nullptr;
        return result;
    };
    
    SpaceBuilder(){space=nullptr;};
    virtual ~SpaceBuilder()=default;
    void createNewSpace(){
        space = new PlanterBoxCollection(0);
    };
    PlantableArea* getSpace(){
        return space;
    };

    virtual void addPlanterBox()=0;
    virtual void addSubCollection()=0;
};

#endif
