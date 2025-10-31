#ifndef GIVEMEDICINECOMMAND_H
#define GIVEMEDICINECOMMAND_H

#include "../src/CareForPlantCommand/CareForPlantCommand.h"
class PlanterBoxCollection;



class GiveMedicineCommand : public CareForPlantCommand {

private:

    int units;

protected:
    PlanterBoxCollection* collection;
    int index;

public:

GiveMedicineCommand(PlanterBoxCollection* collection, int units, int index);

void executeDuty() override;
};

#endif

