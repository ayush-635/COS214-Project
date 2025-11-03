/**
 * @file FlowerPlant.h
 * @author Jano Venter
 * @brief Header file for the FlowerPlant class
 */

#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H

#include "../Plant/Plant.h"

/**
 * @class FlowerPlant
 * @brief Represents a flower plant type
 */
class FlowerPlant : public Plant {
public:
    /**
     * @brief Constructor for FlowerPlant
     * @param id Unique identifier for the plant
     * @param name Name of the plant
     * @param data Shared pointer to plant data
     */
    FlowerPlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other FlowerPlant to copy from
     */
    FlowerPlant(const FlowerPlant& other) : Plant(other) { }

    /**
     * @brief Accept a care visitor
     * @param visitor Reference to the care visitor
     */
    void accept(CareVisitor& visitor) override;
    
    /**
     * @brief Clone the flower plant
     * @return Pointer to the cloned plant
     */
    virtual Plant* clone() override;
};

#endif