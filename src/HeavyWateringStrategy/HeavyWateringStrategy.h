#ifndef HEAVYWATERINGSTRATEGY_H
#define HEAVYWATERINGSTRATEGY_H


#include "../src/WateringStrategy/WateringStrategy.h"


class HeavyWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif
