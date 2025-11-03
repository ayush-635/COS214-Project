#ifndef DEAD_H
#define DEAD_H

#include "../PlantState/PlantState.h"

/**
 * @class Dead
 * @brief Final state representing a dead plant
 * 
 * Plants in this state cannot progress further and are no longer interactive.
 * This is the terminal state in the plant lifecycle.
 */
class Dead : public PlantState {
public:
    /**
     * @brief Handle state behavior for dead plants
     * @param plant The plant to handle (unused in dead state)
     */
    void handle(Plant* plant) override;

    /**
     * @brief Get the name of this state
     * @return std::string Always returns "Dead"
     */
    std::string getName() const override { return "Dead"; }

    /**
     * @brief Check if plant can progress from this state
     * @param plant The plant to check (unused)
     * @return bool Always returns false (dead plants don't progress)
     */
    bool canProgress(Plant* plant) override;

};

#endif