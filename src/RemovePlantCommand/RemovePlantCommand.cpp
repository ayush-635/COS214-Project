#include "RemovePlantCommand.h"
#include "PlantableArea.h"
#include "Plant.h"

/**
 * @brief Constructor sets the plant to remove
 */
RemovePlantCommand::RemovePlantCommand(Plant* plant) : plantToRemove(plant) {}

/**
 * @brief Executes the remove command
 * @param area Pointer to the PlantableArea to remove the plant from
 */
void RemovePlantCommand::executeDuty(PlantableArea* area) {
    if (!area || !plantToRemove) return;

    
    area->removePlant(plantToRemove);
}
