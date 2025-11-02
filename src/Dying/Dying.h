#ifndef DYING_H
#define DYING_H

#include "../PlantState/PlantState.h"

/**
 * @class Dying
 * @brief State representing a plant in critical condition
 * 
 * Plants enter this state when they lack water or fertilizer.
 * They can recover if given proper care, or progress to Dead state if neglected.
 */
class Dying : public PlantState {
private:
    std::string previousState;///< The state the plant was in before dying

public:
    /**
     * @brief Construct a new Dying state
     * @param prevState The state name before entering dying state
     */
    Dying(const std::string& prevState = "Seedling");

    /**
     * @brief Handle state behavior for dying plants
     * @param plant The plant to handle
     */
    void handle(Plant* plant) override;

    /**
     * @brief Get the name of this state
     * @return std::string Always returns "Dying"
     */
    std::string getName() const override { return "Dying"; }

    /**
     * @brief Check if plant can progress to Dead state
     * @param plant The plant to check
     * @return bool True if plant meets death conditions
     */
    bool canProgress(Plant* plant) override;

    /**
     * @brief Get the previous state before dying
     * @return std::string The name of the previous state
     */
    std::string getPreviousState() const { return previousState; }
};

#endif