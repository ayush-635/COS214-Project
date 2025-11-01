#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H

#include "src/Plant/Plant.h"

/**
 * @class SucculentPlant
 * @brief Concrete plant class representing succulent-type plants
 */
class SucculentPlant : public Plant {
public:
    /**
     * @brief Construct a new Succulent Plant object
     * @param id Unique identifier for the plant
     * @param name Display name of the plant
     * @param data Shared plant data configuration
     */
    SucculentPlant(const std::string& id, const std::string& name, 
                   std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other The SucculentPlant to copy from
     */
    SucculentPlant(const SucculentPlant& other) : Plant(other) { }

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
