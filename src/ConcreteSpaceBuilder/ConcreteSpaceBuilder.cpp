#include "ConcreteSpaceBuilder.h"
#include "../PlanterBox/PlanterBox.h"
#include "../PlanterBoxCollection/PlanterBoxCollection.h"
#include <iostream>

ConcreteSpaceBuilder::ConcreteSpaceBuilder() : SpaceBuilder() {
    std::cout << "ConcreteSpaceBuilder initialized" << std::endl;
}

void ConcreteSpaceBuilder::addPlanterBox()
{
    if (space != nullptr) {
        PlanterBox* box = new PlanterBox();
        space->add(box);
        std::cout << "Added PlanterBox to space" << std::endl;
    }
}

void ConcreteSpaceBuilder::addSubCollection()
{
    if (space != nullptr) {
        PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(space);
        if (collection != nullptr) {
            PlanterBoxCollection* subCollection = new PlanterBoxCollection(collection->getDepth() + 1);
            space->add(subCollection);
            std::cout << "Added SubCollection to space" << std::endl;
        }
    }
}

void ConcreteSpaceBuilder::addDefault()
{
    if (space != nullptr) {
        PlanterBox* box1 = new PlanterBox();
        space->add(box1);
        
        PlanterBox* box2 = new PlanterBox();
        space->add(box2);
        
        std::cout << "Added default components to space" << std::endl;
    }
}

PlantableArea* ConcreteSpaceBuilder::build() {
    std::cout<<"ConcreteSpaceBuilder is building space";
    return SpaceBuilder::build();
}
