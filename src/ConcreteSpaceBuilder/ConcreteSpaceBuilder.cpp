#include "ConcreteSpaceBuilder.h"
#include "../Builder/PlantSpace.h"
#include "../Builder/SpaceComponent.h"

ConcreteSpaceBuilder::ConcreteSpaceBuilder() : SpaceBuilder() {
    // ConcreteSpaceBuilder initialized
}

string ConcreteSpaceBuilder::addDefault() {
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
        
        return "Added default components to space";
    }
    return "Error: Space is null";
}

PlantSpace* ConcreteSpaceBuilder::build() {
    // We can override to add specific behavior if we need to here 
    return SpaceBuilder::build();
}
