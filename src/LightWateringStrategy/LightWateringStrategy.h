/**
 * @file LightWateringStrategy.h
 * @brief Declares the LightWateringStrategy class, which implements a light watering approach.
 */

#ifndef LIGHTWATERINGSTRATEGY_H
#define LIGHTWATERINGSTRATEGY_H

#include "../src/WateringStrategy/WateringStrategy.h"
class PlantableArea;

/**
 * @class LightWateringStrategy
 * @brief Concrete watering strategy that applies a small amount of water to plants.
 *
 * This strategy is suitable for plants that require minimal watering or have low moisture needs.
 */
class LightWateringStrategy : public WateringStrategy {
public:
    /**
     * @brief Applies a light watering method to the given plantable area.
     * @param area Pointer to the PlantableArea object to be watered.
     */
    void waterPlant(PlantableArea* area) override;
};

#endif
