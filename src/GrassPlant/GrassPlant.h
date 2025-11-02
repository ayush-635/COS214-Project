/**
 * @file GrassPlant.h
 * @author Jano Venter
 * @brief Header file for the GrassPlant class
 */

#ifndef GRASSPLANT_H
#define GRASSPLANT_H

#include "../Plant/Plant.h"

/**
 * @class GrassPlant
 * @brief Represents a grass plant type
 */
class GrassPlant : public Plant {
public:
    /**
     * @brief Constructor for GrassPlant
     * @param id Unique identifier for the plant
     * @param name Name of the plant
     * @param data Shared pointer to plant data
     */
    GrassPlant(const std::string& id, const std::string& name, 
               std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other GrassPlant to copy from
     */
    GrassPlant(const GrassPlant& other) : Plant(other) { }
    
    /**
     * @brief Accept a care visitor
     * @param visitor Reference to the care visitor
     */
    void accept(CareVisitor& visitor) override;

    /**
     * @brief Clone the grass plant
     * @return Pointer to the cloned plant
     */
    virtual Plant* clone() override;
};

#endif