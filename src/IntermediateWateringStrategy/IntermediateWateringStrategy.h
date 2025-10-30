#ifndef INTERMEDIATEWATERINGSTRATEGY_H
#define INTERMEDIATEWATERINGSTRATEGY_H


#include "../src/WateringStrategy/WateringStrategy.h"


class IntermediateWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif
