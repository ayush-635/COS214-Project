#ifndef HERBPLANT_H
#define HERBPLANT_H

#include "../Plant/Plant.h"

class HerbPlant : public Plant {
public:
    HerbPlant(const std::string& id, const std::string& name, 
              std::shared_ptr<PlantData> data);
	HerbPlant(const HerbPlant& other) : Plant(other) { }

    void accept(CareVisitor& visitor) override;

    /*
	 * @brief Creates and returns a deep copy of the HerbPlant instance.
	 * 
	 * @return Pointer to the newly cloned HerbPlant instance.
	 * 
	 * @note Implements the clone method from the Plant base class.
	 */
	virtual Plant* clone();
};

#endif