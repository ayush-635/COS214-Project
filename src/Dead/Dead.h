#ifndef DEAD_H
#define DEAD_H

#include "src/PlantState/PlantState.h"

class Dead : public PlantState {
public:
    void handle(Plant* plant) override;
    std::string getName() const override { return "Dead"; }
    bool canProgress(Plant* plant) override;
};

#endif