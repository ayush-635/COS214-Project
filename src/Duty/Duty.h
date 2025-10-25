/**
 * @file Duty.h
 * @brief Defines the Duty interface for all command objects.
 */

#ifndef DUTY_H
#define DUTY_H

class PlantableArea; /// Forward declaration

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
    virtual ~Duty() = default;

    /**
     * @brief Executes the command on the specified PlantableArea.
     * @param area Pointer to the PlantableArea on which the command acts.
     */
    virtual void executeDuty(PlantableArea* area) = 0;
};

#endif // DUTY_H
