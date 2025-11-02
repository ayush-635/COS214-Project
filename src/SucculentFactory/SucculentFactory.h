/**
 * @file SucculentFactory.h
 * @author Jano Venter
 * @brief Header file for the SucculentFactory class
 */

#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

class Plant;

/**
 * @class SucculentFactory
 * @brief Factory class for creating succulent plants
 */
class SucculentFactory : public PlantFactory {
public:
    /**
     * @brief Creates a new succulent plant instance
     * @param name The name of the succulent plant prototype to clone
     * @return Pointer to the newly created succulent plant instance
     */
    virtual Plant* createPlant(std::string name) override;
};

#endif