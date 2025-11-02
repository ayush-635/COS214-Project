/**
 * @file GrassFactory.h
 * @author Jano Venter
 * @brief Header file for the GrassFactory class
 */

#ifndef GRASSFACTORY_H
#define GRASSFACTORY_H

#include "../PlantFactory/PlantFactory.h"

/**
 * @class GrassFactory
 * @brief Factory class for creating grass plants
 */
class GrassFactory : public PlantFactory {
public:
    /**
     * @brief Creates a new grass plant instance
     * @param name The name of the grass plant prototype to clone
     * @return Pointer to the newly created grass plant instance
     */
    virtual Plant* createPlant(std::string name) override;
};

#endif