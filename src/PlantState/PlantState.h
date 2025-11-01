#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>

class Plant;

class PlantState {
public:
    virtual ~PlantState() = default;
    virtual void handle(Plant* plant) = 0;
    virtual std::string getName() const = 0;
    virtual bool canProgress(Plant* plant) = 0;  //each state has its own requirements to progess based on the base type values
};

#endif