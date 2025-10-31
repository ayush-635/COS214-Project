/**
 * @file RemovePlantCommand.h
 * @brief Defines the RemovePlantCommand class, responsible for removing a plant from a planter box.
 */

#ifndef REMOVEPLANTCOMMAND_H
#define REMOVEPLANTCOMMAND_H

#include "../Duty/Duty.h"
class Plant;
class PlanterBoxCollection;

/**
 * @class RemovePlantCommand
 * @brief Command that removes a specified plant from the planter box collection.
 */
class RemovePlantCommand : public Duty {
private:
    Plant* targetPlant; ///< Pointer to the plant that will be removed.

public:
    /**
     * @brief Constructs a RemovePlantCommand.
     * @param collection Pointer to the planter box collection.
     * @param targetPlant Pointer to the plant to remove.
     * @param index The index of the target planter box.
     */
    RemovePlantCommand(PlanterBoxCollection* collection, Plant* targetPlant, int index);

    /**
     * @brief Executes the removal operation for the specified plant.
     */
    void executeDuty() override;
};

#endif
