/**
 * @file NurseryManager.h
 * @author Zaynab Samir
 * @brief Header file for the NurseryManager class
 */

#ifndef NURSERYMANAGER_H
#define NURSERYMANAGER_H
#include "../SpaceBuilder/SpaceBuilder.h"
#include "../PlantableArea/PlantableArea.h"

/**
 * @class NurseryManager
 * @brief Manages the construction of different plantable spaces using the Builder pattern
 */
class NurseryManager {
private:
    SpaceBuilder* builder; /**< Pointer to the space builder */

public:
    /**
     * @brief Default constructor
     */
    NurseryManager() : builder(nullptr){}

    /**
     * @brief Set the builder for space construction
     * @param b Pointer to the space builder
     */
    void setBuilder(SpaceBuilder* b){
        builder = b;
    }

    /**
     * @brief Construct a small plantable space
     * @return Pointer to the constructed small plantable area
     */
    PlantableArea* constructSmallSpace();
    
    /**
     * @brief Construct a medium plantable space
     * @return Pointer to the constructed medium plantable area
     */
    PlantableArea* constructMediumSpace();
    
    /**
     * @brief Construct a large plantable space
     * @return Pointer to the constructed large plantable area
     */
    PlantableArea* constructBigSpace();
};

#endif