/**
 * @file HerbFactory.h
 * @author Jano Venter
 * @brief Header file for the HerbFactory class
 */

#ifndef HERBFACTORY_H
#define HERBFACTORY_H

#include "../PlantFactory/PlantFactory.h"

/**
 * @class HerbFactory
 * @brief Factory class for creating herb plants
 */
class HerbFactory : public PlantFactory {
public:
    /**
     * @brief Creates a new herb plant instance
     * @param name The name of the herb plant prototype to clone
     * @return Pointer to the newly created herb plant instance
     */
    virtual Plant* createPlant(std::string name) override;
};

#endif