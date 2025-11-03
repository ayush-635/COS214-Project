/**
 * @file TreePlant.h
 * @author Jano Venter
 * @brief Header file for the TreePlant class
 */

#ifndef TREEPLANT_H
#define TREEPLANT_H

#include "../Plant/Plant.h"

/**
 * @class TreePlant
 * @brief Represents a tree plant type
 */
class TreePlant : public Plant {
public:
    /**
     * @brief Constructor for TreePlant
     * @param id Unique identifier for the plant
     * @param name Name of the plant
     * @param data Shared pointer to plant data
     */
    TreePlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other TreePlant to copy from
     */
    TreePlant(const TreePlant& other) : Plant(other) { }

    /**
     * @brief Accept a care visitor
     * @param visitor Reference to the care visitor
     */
    void accept(CareVisitor& visitor) override;
    
    /**
     * @brief Clone the tree plant
     * @return Pointer to the cloned plant
     */
    virtual Plant* clone() override;
};

#endif