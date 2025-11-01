#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H

#include "../Plant/Plant.h"

/**
 * @class FlowerPlant
 * @brief Concrete plant class representing flower-type plants
 */
class FlowerPlant : public Plant {
public:
    /**
     * @brief Construct a new Flower Plant object
     * @param id Unique identifier for the plant
     * @param name Display name of the plant
     * @param data Shared plant data configuration
     */
    FlowerPlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other The FlowerPlant to copy from
     */
    FlowerPlant(const FlowerPlant& other) : Plant(other) { }

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
