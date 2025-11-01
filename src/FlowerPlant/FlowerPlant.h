#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H

#include "../Plant/Plant.h"

class FlowerPlant : public Plant {
public:
    FlowerPlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    FlowerPlant(const FlowerPlant& other) : Plant(other) { }

    void accept(CareVisitor& visitor) override;
	
    /*
	 * @brief Creates and returns a deep copy of the FlowerPlant instance.
	 * 
	 * @return Pointer to the newly cloned FlowerPlant instance.
	 * 
	 * @note Implements the clone method from the Plant base class.
	 */
	virtual Plant* clone() override;
};

#endif
