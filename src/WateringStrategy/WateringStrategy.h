/**
 * @file WateringStrategy.h
 * @brief Declares the WateringStrategy abstract base class, which defines the interface for plant watering strategies.
 */

#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

class PlantableArea;

/**
 * @class WateringStrategy
 * @brief Abstract base class representing a general strategy for watering a plantable area.
 *
 * This class defines the interface for different watering strategies such as light, intermediate, and heavy watering.
 */
class WateringStrategy {
public:
    /**
     * @brief Constructs a WateringStrategy object.
     */
    WateringStrategy();

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~WateringStrategy();

    /**
     * @brief Waters the given plantable area according to the implemented strategy.
     * @param area Pointer to the PlantableArea object to be watered.
     */
    virtual void waterPlant(PlantableArea* area) = 0;
};

#endif

