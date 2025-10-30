#ifndef MATURE_H
#define MATURE_H

#include "src/PlantState/PlantState.h"

class Mature : public PlantState {
public:
    void handle(Plant* plant) override;
    std::string getName() const override { return "Mature"; }
    bool canProgress(Plant* plant) override;
};

#endif