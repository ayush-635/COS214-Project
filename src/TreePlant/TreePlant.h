#ifndef TREEPLANT_H
#define TREEPLANT_H

#include "src/Plant/Plant.h"

class TreePlant : public Plant {
public:
    TreePlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    TreePlant(const TreePlant& other) : Plant(other) { }

    void accept(CareVisitor& visitor) override;
	
	virtual Plant* clone() override;
};

#endif