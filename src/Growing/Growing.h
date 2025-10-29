#ifndef GROWING_H
#define GROWING_H

#include "../PlantState/PlantState.h"

class Growing : public PlantState {
public:
    void handle(Plant* plant) override;
    std::string getName() const override { return "Growing"; }
    bool canProgress(Plant* plant) override;
};

#endif