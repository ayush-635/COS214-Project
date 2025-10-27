#ifndef REMOVEPLANTCOMMAND_H
#define REMOVEPLANTCOMMAND_H

#include "Duty.h"


/**
 * @class RemovePlantCommand
 * @brief Concrete command to remove a plant from a PlantableArea.
 * 
 * Implements the Command pattern by encapsulating the action of
 * removing a plant. Can be executed by a StaffMember (Invoker).
 */
class RemovePlantCommand : public Duty {
	
	Plant* plantToRemove; /// The plant that will be removed


public:

	 /**
     * @brief Constructor
     * @param plant Pointer to the plant to remove
     */
    RemovePlantCommand(Plant* plant);

     /**
     * @brief Executes the command to remove a plant from the given PlantableArea.
     * @param area Pointer to the PlantableArea from which the plant will be removed.
     */
	void executeDuty(PlantableArea* area);
};

#endif
