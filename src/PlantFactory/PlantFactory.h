/**
 * @file PlantFactory.h
 * @author Jano Venter
 * @brief Header file for the PlantFactory class
 */

#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <string>
#include <map>

class Plant;

/**
 * @class PlantFactory
 * @brief Abstract factory class for creating plants using prototype pattern
 */
class PlantFactory {
private:
    std::map<std::string, Plant*> plantProtoypes; /**< Map of plant prototypes */

public:
    /**
     * @brief Virtual destructor
     */
    virtual ~PlantFactory();

    /**
     * @brief Add a plant prototype to the factory
     * @param prototype Pointer to plant prototype
     */
    virtual void addPlantPrototype(Plant* prototype);

    /**
     * @brief Get all plant prototypes
     * @return Reference to plant prototypes map
     */
    std::map<std::string, Plant*>& getPlantPrototypes() {
        return plantProtoypes;
    }

    /**
     * @brief Pure virtual method to create a plant
     * @param name Name of the plant to create
     * @return Pointer to created plant
     */
    virtual Plant* createPlant(std::string name) = 0;
};

#endif