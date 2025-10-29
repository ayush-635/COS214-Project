#ifndef DYING_H
#define DYING_H

#include "src/PlantState/PlantState.h"

class Dying : public PlantState {
private:
    std::string previousState;

public:
    Dying(const std::string& prevState = "Seedling");
    void handle(Plant* plant) override;
    std::string getName() const override { return "Dying"; }
    bool canProgress(Plant* plant) override;
    std::string getPreviousState() const { return previousState; }
};

#endif