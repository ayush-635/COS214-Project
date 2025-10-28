#include "GiveMedicineCommand.h"


/**
 * @brief Executes the command to give medicine to the PlantableArea.
 */

GiveMedicineCommand::GiveMedicineCommand(PlanterBoxCollection* collection, int boxIndex, int units)
    : collection(collection), boxIndex(boxIndex), units(units) {}

 void GiveMedicineCommand::executeDuty() {
    if (!collection) return;

    collection->giveMedicine(units, boxIndex);
}
