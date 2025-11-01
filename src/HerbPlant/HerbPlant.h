#ifndef HERBPLANT_H
#define HERBPLANT_H

#include "../Plant/Plant.h"

/**
 * @class HerbPlant
 * @brief Concrete plant class representing herb-type plants
 */
class HerbPlant : public Plant {
public:
    /**
     * @brief Construct a new Herb Plant object
     * @param id Unique identifier for the plant
     * @param name Display name of the plant
     * @param data Shared plant data configuration
     */
    HerbPlant(const std::string& id, const std::string& name, 
              std::shared_ptr<PlantData> data);
    
    /**
     * @brief Copy constructor
     * @param other The HerbPlant to copy from
     */
    HerbPlant(const HerbPlant& other) : Plant(other) { }

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
