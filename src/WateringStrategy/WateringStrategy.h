#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

class PlantableArea;

class WateringStrategy {
public:
    WateringStrategy();
    virtual ~WateringStrategy();
    virtual void waterPlant(PlantableArea* area) = 0;
};

#endif