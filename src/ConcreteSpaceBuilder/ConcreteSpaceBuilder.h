/**
 * @file ConcreteSpaceBuilder.h
 * @brief Concrete implementation of the SpaceBuilder
 * @author Zaynab Samir
 * 
 * This file implements the concrete builder that constructs plantable
 * spaces with planter boxes and nested collections.
 */
#ifndef CONCRETESPACEBUILDER_H
#define CONCRETESPACEBUILDER_H
#include "../SpaceBuilder/SpaceBuilder.h"
#include "../PlanterBox/PlanterBox.h"

/**
 * @class ConcreteSpaceBuilder
 * @brief Concrete builder for constructing plantable spaces
 * 
 * Implements the SpaceBuilder interface to create PlantableArea structures
 * with PlanterBoxes and nested PlanterBoxCollections. Provides methods to:
 * - Add individual planter boxes
 * - Add nested sub-collections
 * - Add default components (2 boxes)
 * 
 * Used by NurseryManager (Director) to construct small, medium, and large spaces.
 * 
 * @note Part of the Builder design pattern
 */
class ConcreteSpaceBuilder : public SpaceBuilder {
public:
    /**
     * @brief Constructor
     * 
     * Initializes the concrete builder and prints initialization message.
     */
    ConcreteSpaceBuilder();

    /**
     * @brief Adds a single planter box to the space
     * 
     * Creates a new PlanterBox and adds it to the current space.
     * If space is null, no action is taken.
     * Prints confirmation message upon successful addition.
     */
    void addPlanterBox() override;

    /**
     * @brief Adds a nested sub-collection to the space
     * 
     * Creates a new PlanterBoxCollection with appropriate depth
     * (parent depth + 1) and adds it to the current space.
     * Only works if current space is a PlanterBoxCollection.
     * Prints confirmation message upon successful addition.
     * 
     * @note Depth validation is handled by PlanterBoxCollection
     */
    void addSubCollection() override;

    /**
     * @brief Adds default components (2 planter boxes)
     * 
     * Convenience method that adds two PlanterBox components to the space.
     * Used for creating basic space configurations.
     * Prints confirmation message upon completion.
     */
    void addDefault();

    /**
     * @brief Finalizes and returns the built space
     * @return Pointer to the completed PlantableArea
     * 
     * Overrides the base build() method to add logging.
     * Prints build confirmation and returns the constructed space.
     */
    PlantableArea* build();
};

#endif
