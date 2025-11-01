#ifndef GROWING_H
#define GROWING_H

#include "../PlantState/PlantState.h"

/**
 * @class Growing
 * @brief State representing plants in active growth phase
 */
class Growing : public PlantState {
public:
    /**
     * @brief Handle state behavior for growing plants
     * @param plant The plant to handle
     */
    void handle(Plant* plant) override;
    
    /**
     * @brief Get the name of this state
     * @return std::string Always returns "Growing"
     */
    std::string getName() const override { return "Growing"; }
    
    /**
     * @brief Check if plant can progress to Mature state
     * @param plant The plant to check
     * @return bool True if plant has received sufficient resources
     */
    bool canProgress(Plant* plant) override;
};

#endif
