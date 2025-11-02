/**
 * @file GiveMedicineCommand.h
 * @brief Defines the GiveMedicineCommand class, which administers medicine to a plant.
 */
#ifndef GIVEMEDICINECOMMAND_H
#define GIVEMEDICINECOMMAND_H

#include "../CareForPlantCommand/CareForPlantCommand.h"
class PlanterBoxCollection;

/**
 * @class GiveMedicineCommand
 * @brief Command that administers medicine to a specific plant in a planter box.
 */
class GiveMedicineCommand : public CareForPlantCommand {
private:
    int units;///< Number of medicine units to apply.

protected:
    PlanterBoxCollection* collection;;///< Holds the collection of PlanterBoxes.
    int index;///< Points to an index in the collection to give fertilizer.

public:
    /**
     * @brief Constructs a GiveMedicineCommand.
     * @param collection Pointer to the planter box collection.
     * @param units Amount of medicine to apply.
     * @param index The index of the target planter box.
     */
GiveMedicineCommand(PlanterBoxCollection* collection, int units, int index);

/**
 * @brief Executes the medicine administration operation.
*/
void executeDuty() override;
};

#endif

