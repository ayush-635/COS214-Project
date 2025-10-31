/**
 * @file GiveFertilizerCommand.h
 * @brief Defines the GiveFertilizerCommand class, which provides fertilizer to a plant.
 */

#ifndef GIVEFERTILIZERCOMMAND_H
#define GIVEFERTILIZERCOMMAND_H

#include "../src/CareForPlantCommand/CareForPlantCommand.h"
class PlanterBoxCollection;

/**
 * @class GiveFertilizerCommand
 * @brief Command that applies fertilizer to a specific plant in a planter box.
 */
class GiveFertilizerCommand : public CareForPlantCommand {

private:
    int units; ///< Number of fertilizer units to apply.

public:
    /**
     * @brief Constructs a GiveFertilizerCommand.
     * @param collection Pointer to the planter box collection.
     * @param units Amount of fertilizer to apply.
     * @param index The index of the target planter box.
     */
    GiveFertilizerCommand(PlanterBoxCollection* collection, int units, int index);

    /**
     * @brief Executes the fertilizer application operation.
     */
    void executeDuty() override;
};

#endif
