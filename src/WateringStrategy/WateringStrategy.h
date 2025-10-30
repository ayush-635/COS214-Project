#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include "../src/PlantableArea/PlantableArea.h" 


class WateringStrategy {
public:
    WateringStrategy();
    virtual ~WateringStrategy();

    
    virtual void waterPlant(PlantableArea* area) = 0;
};

#endif
