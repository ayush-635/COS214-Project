#ifndef GIVEMEDICINECOMMAND_H
#define GIVEMEDICINECOMMAND_H

#include "CareForPlantCommand.h"


/**
 * @class GiveMedicineCommand
 * @brief Concrete command to give medicine to plants.
 */
class GiveMedicineCommand : public CareForPlantCommand {
public:
    void executeDuty(PlantableArea* area);
};

#endif

