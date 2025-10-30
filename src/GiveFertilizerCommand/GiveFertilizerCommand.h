#ifndef GIVEFERTILIZERCOMMAND_H
#define GIVEFERTILIZERCOMMAND_H

#include "../src/CareForPlantCommand/CareForPlantCommand.h"



class GiveFertilizerCommand : public CareForPlantCommand {

private:

    int units;

public:

	GiveFertilizerCommand(PlanterBoxCollection* collection, int units, int index);

    
    void executeDuty() override;
};

#endif
