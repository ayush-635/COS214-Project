#include "GiveMedicineCommand.h"


/**
 * @brief Executes the command to give medicine to the PlantableArea.
 */
void GiveMedicineCommand::executeDuty(PlantableArea* area) {
    if (!area) return;
    area->giveMedicine();
}
