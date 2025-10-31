/**
 * @file CareForPlantCommand.h
 * @brief Defines the CareForPlantCommand abstract class, serving as a base for plant care commands.
 */

#ifndef CAREFORPLANTCOMMAND_H
#define CAREFORPLANTCOMMAND_H

#include "../src/Duty/Duty.h"

/**
 * @class CareForPlantCommand
 * @brief Abstract base class for commands that care for plants (e.g., watering, fertilizing, etc.).
 */
class CareForPlantCommand : public Duty {
public:
    /**
     * @brief Constructs a CareForPlantCommand.
     * @param collection Pointer to the planter box collection.
     * @param index The index of the planter box to act upon.
     */
    CareForPlantCommand(PlanterBoxCollection* collection, int index)
        : Duty(collection, index) {}

    /**
     * @brief Executes the plant care operation.
     */
    virtual void executeDuty() = 0;
};

#endif
