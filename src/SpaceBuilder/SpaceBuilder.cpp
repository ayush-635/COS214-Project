#include "SpaceBuilder.h"
#include "PlantSpace.h"
#include "SpaceComponent.h"
#include <iostream>

SpaceBuilder::SpaceBuilder() {
    space = new PlantSpace();
    space->name = "Unnamed Space";
}

void SpaceBuilder::setSize(int width, int length) {
    // This is to Set the size for the next component to be added
    if (space != nullptr) {
        SpaceComponent* component = new SpaceComponent();
        component->width = width;
        component->length = length;
        space->subspaces.push_back(component);
        std::cout << "Set space size: " << width << "x" << length << std::endl;
    }
}

void SpaceBuilder::reset() {
    // Delete current space and create a new one
    if (space != nullptr) {
        // Clean up subspaces
        for (SpaceComponent* component : space->subspaces) {
            delete component;
        }
        delete space;
    }
    space = new PlantSpace();
    space->name = "Unnamed Space";
    std::cout << "Builder reset" << std::endl;
}

void SpaceBuilder::setName(int name) {
	// Set the name of the space
    if (space != nullptr) {
        space->name = "Space_" + std::to_string(name);
        std::cout << "Set space name to: " << space->name << std::endl;
    }
}

void SpaceBuilder::addSubSpace() {
    // Add a default subspace component
    if (space != nullptr) {
        space->addComponent();
    }
}

PlantSpace* SpaceBuilder::build() {
    // Return the built space and reset for next build
    PlantSpace* result = space;
    space = nullptr;  // Transfer ownership
    std::cout << "Space built successfully" << std::endl;
    return result;
}
