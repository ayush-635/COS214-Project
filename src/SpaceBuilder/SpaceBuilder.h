/**
 * @file SpaceBuilder.h
 * @brief Abstract builder for constructing plantable spaces
 * @author Zaynab Samir
 * 
 * This file defines the SpaceBuilder abstract class which is part of the
 * Builder design pattern for creating complex PlantableArea structures.
 */

#ifndef SPACEBUILDER_H
#define SPACEBUILDER_H

#include <string>
using namespace std;
#include "../PlantableArea/PlantableArea.h"
#include "../PlanterBoxCollection/PlanterBoxCollection.h"

/**
 * @class SpaceBuilder
 * @brief Abstract builder for constructing plantable space structures
 * 
 * This class defines the interface for building complex PlantableArea
 * structures. Concrete builders (like ConcreteSpaceBuilder) implement
 * the specific construction steps. This implements the Builder design pattern.
 * 
 * @note Part of the Builder design pattern
 */
class SpaceBuilder {
protected:
    PlantableArea* space;  ///< The space being constructed

public:
    /**
     * @brief Finalizes and returns the constructed space
     * @return Pointer to the completed PlantableArea
     * 
     * Returns the constructed space and resets the internal space pointer
     * to nullptr, preparing the builder for the next construction.
     */
    PlantableArea* build(){
        PlantableArea* result = space;
        space = nullptr;
        return result;
    };
    
    /**
     * @brief Default constructor
     * 
     * Initializes the space pointer to nullptr.
     */
    SpaceBuilder(){space=nullptr;};
    
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~SpaceBuilder()=default;
    
    /**
     * @brief Creates a new space (root collection)
     * 
     * Initializes the space as a new PlanterBoxCollection at depth 0.
     * This should be called before adding components to the space.
     */
    void createNewSpace(){
        space = new PlanterBoxCollection(0);
    };
    
    /**
     * @brief Gets the current space being built
     * @return Pointer to the PlantableArea under construction
     */
    PlantableArea* getSpace(){
        return space;
    };

    /**
     * @brief Adds a planter box to the space
     * 
     * Pure virtual function to be implemented by concrete builders.
     * Should add a single PlanterBox component to the space.
     */
    virtual void addPlanterBox()=0;
    
    /**
     * @brief Adds a sub-collection to the space
     * 
     * Pure virtual function to be implemented by concrete builders.
     * Should add a nested PlanterBoxCollection to create hierarchical structure.
     */
    virtual void addSubCollection()=0;
};

#endif
