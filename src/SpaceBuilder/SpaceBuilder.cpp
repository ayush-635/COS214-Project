#include "SpaceBuilder.h"
#include "PlantSpace.h"
#include "SpaceComponent.h"

SpaceBuilder::SpaceBuilder() {
    space = new PlantSpace();
    space->name = "Unnamed Space";
}

string SpaceBuilder::setSize(int width, int length) {
    // This is to Set the size for the next component to be added
    if (space != nullptr) {
        SpaceComponent* component = new SpaceComponent();
        component->width = width;
        component->length = length;
        space->subspaces.push_back(component);
        return "Set space size: " + std::to_string(width) + "x" + std::to_string(length);
    }
    return "Error: Space is null";
}

string SpaceBuilder::reset() {
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
    return "Builder reset";
}

string SpaceBuilder::setName(int name) {
	// Set the name of the space
    if (space != nullptr) {
        space->name = "Space_" + std::to_string(name);
        return "Set space name to: " + space->name;
    }
    return "Error: Space is null";
}

string SpaceBuilder::addSubSpace() {
    // Add a default subspace component
    if (space != nullptr) {
        space->addComponent();
        return "Subspace added";
    }
    return "Error: Space is null";
}

PlantSpace* SpaceBuilder::build() {
    // Return the built space and reset for next build
    PlantSpace* result = space;
    space = nullptr;  // Transfer ownership
    return result;
}
