#include "ConcreteSpaceBuilder.h"
#include "PlantSpace.h"
#include "SpaceComponent.h"
#include <iostream>

ConcreteSpaceBuilder::ConcreteSpaceBuilder() : SpaceBuilder() {
    std::cout << "ConcreteSpaceBuilder initialized" << std::endl;
}

void ConcreteSpaceBuilder::addDefault() {
    // Add default config for a plant space
    if (space != nullptr) {
        // Add default sized components
        SpaceComponent* defaultComp1 = new SpaceComponent();
        defaultComp1->width = 5;
        defaultComp1->length = 5;
        space->subspaces.push_back(defaultComp1);
        
        SpaceComponent* defaultComp2 = new SpaceComponent();
        defaultComp2->width = 10;
        defaultComp2->length = 8;
        space->subspaces.push_back(defaultComp2);
        
        std::cout << "Added default components to space" << std::endl;
    }
}

PlantSpace* ConcreteSpaceBuilder::build() {
    // We can override to add specific behavior if we need to here 
    std::cout << "ConcreteSpaceBuilder building space..." << std::endl;
    return SpaceBuilder::build();
}
