/**
 * @file SucculentPlant.h
 * @author Jano Venter
 * @brief Header file for the SucculentPlant class
 */

#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H

#include "../Plant/Plant.h"

/**
 * @class SucculentPlant
 * @brief Represents a succulent plant type
 */
class SucculentPlant : public Plant {
public:
    /**
     * @brief Constructor for SucculentPlant
     * @param id Unique identifier for the plant
     * @param name Name of the plant
     * @param data Shared pointer to plant data
     */
    SucculentPlant(const std::string& id, const std::string& name, 
                   std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other SucculentPlant to copy from
     */
    SucculentPlant(const SucculentPlant& other) : Plant(other) { }

    /**
     * @brief Accept a care visitor
     * @param visitor Reference to the care visitor
     */
    void accept(CareVisitor& visitor) override;
    
    /**
     * @brief Clone the succulent plant
     * @return Pointer to the cloned plant
     */
    virtual Plant* clone() override;
};

#endif