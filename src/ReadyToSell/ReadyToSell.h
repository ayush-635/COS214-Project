#ifndef READYTOSELL_H
#define READYTOSELL_H

#include "src/PlantState/PlantState.h"

class ReadyToSell : public PlantState {
public:
    void handle(Plant* plant) override;
    std::string getName() const override { return "ReadyToSell"; }
    bool canProgress(Plant* plant) override;
};

#endif