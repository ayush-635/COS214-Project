#ifndef GRASSPLANT_H
#define GRASSPLANT_H

#include "../Plant/Plant.h"

class GrassPlant : public Plant {
public:
    GrassPlant(const std::string& id, const std::string& name, 
               std::shared_ptr<PlantData> data);
    GrassPlant(const GrassPlant& other) : Plant(other) { }
	
    void accept(CareVisitor& visitor) override;

    /*
	 * @brief Creates and returns a deep copy of the GrassPlant instance.
	 * 
	 * @return Pointer to the newly cloned GrassPlant instance.
	 * 
	 * @note Implements the clone method from the Plant base class.
	 */
    virtual Plant* clone() override;
};

#endif