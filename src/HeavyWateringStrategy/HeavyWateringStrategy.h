#ifndef HEAVYWATERINGSTRATEGY_H
#define HEAVYWATERINGSTRATEGY_H

#include "WateringStrategy.h"

/**
 * @class HeavyWateringStrategy
 * @brief Concrete strategy for heavy watering.
 */
class HeavyWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif
