/**
 * @file TreeFactory.h
 * @author Jano Venter
 * @brief Header file for the TreeFactory class
 */

#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "src/PlantFactory/PlantFactory.h"

/**
 * @class TreeFactory
 * @brief Factory class for creating tree plants
 */
class TreeFactory : public PlantFactory {
public:
    /**
     * @brief Creates a new tree plant instance
     * @param name The name of the tree plant prototype to clone
     * @return Pointer to the newly created tree plant instance
     */
    virtual Plant* createPlant(std::string name) override;
};

#endif