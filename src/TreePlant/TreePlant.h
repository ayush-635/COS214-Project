#ifndef TREEPLANT_H
#define TREEPLANT_H

#include "../Plant/Plant.h"

class TreePlant : public Plant {
public:
    TreePlant(const std::string& id, const std::string& name, 
              std::shared_ptr<PlantData> data);
    void accept(CareVisitor& visitor) override;
};

#endif