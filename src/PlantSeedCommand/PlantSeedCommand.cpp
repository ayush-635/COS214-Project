#include "PlantSeedCommand.h"
#include "PlantableArea.h"
#include "Plant.h"

/**
 * @brief Constructor for PlantSeedCommand
 * @param seed Pointer to the Plant object to be planted
 */
PlantSeedCommand::PlantSeedCommand(Plant* seed) : seed(seed) {}

/**
 * @brief Executes the command to plant a seed in the given PlantableArea
 * @param area Pointer to the PlantableArea where the seed is planted
 */
void PlantSeedCommand::executeDuty(PlantableArea* area) {
	
	if (!area || !seed) return;

    
        area->populate(seed); 
    

}
