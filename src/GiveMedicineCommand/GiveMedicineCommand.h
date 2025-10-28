#ifndef GIVEMEDICINECOMMAND_H
#define GIVEMEDICINECOMMAND_H

#include "CareForPlantCommand.h"
#include "PlanterBoxCollection.h"


/**
 * @class GiveMedicineCommand
 * @brief Concrete command to give medicine to plants.
 */
class GiveMedicineCommand : public CareForPlantCommand {

private:
    PlanterBoxCollection* collection;
    int boxIndex;
    int units;
public:

GiveMedicineCommand(PlanterBoxCollection* collection, int boxIndex, int units);
    void executeDuty() override;
};

#endif

