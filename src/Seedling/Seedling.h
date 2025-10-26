#ifndef SEEDLING_H
#define SEEDLING_H

#include "src/PlantState/PlantState.h"

class Seedling : public PlantState {
public:
    void handle(Plant* plant) override;
    std::string getName() const override { return "Seedling"; }
    bool canProgress(Plant* plant) override;
};

#endif