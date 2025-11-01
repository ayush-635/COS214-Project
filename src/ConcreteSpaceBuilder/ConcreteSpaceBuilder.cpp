/**
 * @file ConcreteSpaceBuilder.cpp
 * @brief Implementation of ConcreteSpaceBuilder
 * @author Zaynab Samir
 */

#include "ConcreteSpaceBuilder.h"
#include "../PlanterBox/PlanterBox.h"
#include "../PlanterBoxCollection/PlanterBoxCollection.h"
#include <iostream>

/**
 * @brief Constructor implementation
 * 
 * Calls base class constructor and prints initialization message.
 */
ConcreteSpaceBuilder::ConcreteSpaceBuilder() : SpaceBuilder() {
    std::cout << "ConcreteSpaceBuilder initialized" << std::endl;
}

/**
 * @brief Adds a planter box to the current space
 * 
 * Creates and adds a new PlanterBox to the space if space is not null.
 */
void ConcreteSpaceBuilder::addPlanterBox()
{
    if (space != nullptr) {
        PlanterBox* box = new PlanterBox();
        space->add(box);
        std::cout << "Added PlanterBox to space" << std::endl;
    }
}

/**
 * @brief Adds a nested collection to the space
 * 
 * Creates a sub-collection with depth = parent_depth + 1 and adds it.
 * Only works if current space is a PlanterBoxCollection.
 */
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

/**
 * @brief Adds two default planter boxes
 * 
 * Convenience method for quickly adding 2 boxes to a space.
 */
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

/**
 * @brief Finalizes the space construction
 * 
 * Prints build message and calls base class build() method.
 * 
 * @return Completed PlantableArea structure
 */
PlantableArea* ConcreteSpaceBuilder::build() {
    std::cout<<"ConcreteSpaceBuilder is building space";
    return SpaceBuilder::build();
}
