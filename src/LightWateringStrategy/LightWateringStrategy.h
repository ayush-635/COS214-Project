#ifndef LIGHTWATERINGSTRATEGY_H
#define LIGHTWATERINGSTRATEGY_H

#include "WateringStrategy.h"

/**
 * @class LightWateringStrategy
 * @brief Concrete strategy for light watering.
 */
class LightWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif

