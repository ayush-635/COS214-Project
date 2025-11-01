#ifndef TREEPLANT_H
#define TREEPLANT_H

#include "../Plant/Plant.h"

/**
 * @class TreePlant
 * @brief Concrete plant class representing tree-type plants
 */
class TreePlant : public Plant {
public:
    /**
     * @brief Construct a new Tree Plant object
     * @param id Unique identifier for the plant
     * @param name Display name of the plant
     * @param data Shared plant data configuration
     */
    TreePlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other The TreePlant to copy from
     */
    TreePlant(const TreePlant& other) : Plant(other) { }

    /**
     * @brief Accept a care visitor
     * @param visitor The care visitor to accept
     */
    void accept(CareVisitor& visitor) override;
    
    /**
     * @brief Create a clone of this plant
     * @return Plant* Pointer to the cloned plant
     */
    virtual Plant* clone() override;
};

#endif
