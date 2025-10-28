#ifndef GIVEFERTILIZERCOMMAND_H
#define GIVEFERTILIZERCOMMAND_H

#include "CareForPlantCommand.h"
#include "PlanterBoxCollection.h"


/**
 * @class GiveFertilizerCommand
 * @brief Concrete command to give fertilizer to plants.
 */
class GiveFertilizerCommand : public CareForPlantCommand {

private:
	int units;
    PlanterBoxCollection* collection;
    int boxIndex;
public:

	GiveFertilizerCommand(PlanterBoxCollection* collection, int boxIndex, int units);

    /// Executes the command to give fertilizer
    void executeDuty() override;
};

#endif
