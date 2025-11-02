/**
 * @file HerbPlant.h
 * @author Jano Venter
 * @brief Header file for the HerbPlant class
 */

#ifndef HERBPLANT_H
#define HERBPLANT_H

#include "../Plant/Plant.h"

/**
 * @class HerbPlant
 * @brief Represents a herb plant type
 */
class HerbPlant : public Plant {
public:
    /**
     * @brief Constructor for HerbPlant
     * @param id Unique identifier for the plant
     * @param name Name of the plant
     * @param data Shared pointer to plant data
     */
    HerbPlant(const std::string& id, const std::string& name, 
              std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other HerbPlant to copy from
     */
    HerbPlant(const HerbPlant& other) : Plant(other) { }

    /**
     * @brief Accept a care visitor
     * @param visitor Reference to the care visitor
     */
    void accept(CareVisitor& visitor) override;

    /**
     * @brief Clone the herb plant
     * @return Pointer to the cloned plant
     */
    virtual Plant* clone() override;
};

#endif