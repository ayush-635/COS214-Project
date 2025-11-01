#ifndef TREEPLANT_H
#define TREEPLANT_H

#include "../Plant/Plant.h"

class TreePlant : public Plant {
public:
    TreePlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    TreePlant(const TreePlant& other) : Plant(other) { }

    void accept(CareVisitor& visitor) override;
	
    /*
	 * @brief Creates and returns a deep copy of the TreePlant instance.
	 * 
	 * @return Pointer to the newly cloned TreePlant instance.
	 * 
	 * @note Implements the clone method from the Plant base class.
	 */
	virtual Plant* clone() override;
};

#endif