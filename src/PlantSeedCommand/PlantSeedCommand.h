#ifndef PLANTSEEDCOMMAND_H
#define PLANTSEEDCOMMAND_H

#include "Duty.h"  
#include "Plant.h"


/**
 * @class PlantSeedCommand
 * @brief Concrete command to plant a seed in a PlantableArea.
 * 
 * Implements the Command pattern by encapsulating the action of planting
 * a seed. The command can be executed by a StaffMember (Invoker).
 */

class PlantSeedCommand : public Duty {

public:
    /// Pointer to the Plant to be planted
	Plant* seed;

    /**
     * @brief Constructor
     * @param seed Pointer to the Plant object to be planted
     */
	PlantSeedCommand(Plant* seed);

    /**
     * @brief Executes the planting command on the specified PlantableArea.
     * @param area Pointer to the PlantableArea where the seed is planted
     */
	void executeDuty(PlantableArea* area);
};

#endif
