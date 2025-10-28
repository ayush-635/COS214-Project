/**
 * @file Duty.h
 * @brief Defines the Duty interface for all command objects.
 */

#ifndef DUTY_H
#define DUTY_H

#include "PlantableArea.h"
#include "Plant.h"

/**
 * @class Duty
 * @brief Abstract Command interface for all plant-related operations.
 */
class Duty {
public:
    /**
     * @brief Default constructor 
     */
    Duty();

    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~Duty();

    /**
     * @brief Executes the command on the specified PlantableArea.
     * @param area Pointer to the PlantableArea on which the command acts.
     */
    virtual void executeDuty() = 0;
};

#endif 
