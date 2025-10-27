#ifndef GIVEFERTILIZERCOMMAND_H
#define GIVEFERTILIZERCOMMAND_H

#include "CareForPlantCommand.h"


/**
 * @class GiveFertilizerCommand
 * @brief Concrete command to give fertilizer to plants.
 */
class GiveFertilizerCommand : public CareForPlantCommand {

	int units;
public:

	GiveFertilizerCommand(int units);

    /// Executes the command to give fertilizer
    void executeDuty(PlantableArea* area);
};

#endif
