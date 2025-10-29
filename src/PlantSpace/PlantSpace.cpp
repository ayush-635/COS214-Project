#include "PlantSpace.h"
#include "SpaceComponent.h"
#include <iostream>

void PlantSpace::addComponent() {
    // Method to Add a default component to the plant space
    SpaceComponent* newComponent = new SpaceComponent();
    newComponent->width = 10;  // This is the Default width
    newComponent->length = 10;  // And this is the Default length
    subspaces.push_back(newComponent);
    std::cout << "Added new component to " << name << std::endl;
}

void PlantSpace::removeComponent() {
    // And a Method to Remove the last component if it exists
    if (!subspaces.empty()) {
        SpaceComponent* component = subspaces.back();
        subspaces.pop_back();
        delete component;
        std::cout << "Removed component from " << name << std::endl;
    } else {
        std::cout << "No components to remove from " << name << std::endl;
    }
}
