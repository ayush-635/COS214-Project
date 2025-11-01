#ifndef GIVEFERTILIZERCOMMAND_H
#define GIVEFERTILIZERCOMMAND_H

#include "../CareForPlantCommand/CareForPlantCommand.h"

class PlanterBoxCollection;

class GiveFertilizerCommand : public CareForPlantCommand {

private:
    int units;

protected:
    PlanterBoxCollection* collection;
    int index;

public:

	GiveFertilizerCommand(PlanterBoxCollection* collection, int units, int index);

    
    void executeDuty() override;
};

#endif
