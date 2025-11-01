#ifndef MATURE_H
#define MATURE_H

#include "../PlantState/PlantState.h"

/**
 * @class Mature
 * @brief State representing fully grown plants ready for final stage
 */
class Mature : public PlantState {
public:
    /**
     * @brief Handle state behavior for mature plants
     * @param plant The plant to handle
     */
    void handle(Plant* plant) override;
    
    /**
     * @brief Get the name of this state
     * @return std::string Always returns "Mature"
     */
    std::string getName() const override { return "Mature"; }
    
    /**
     * @brief Check if plant can progress to ReadyToSell state
     * @param plant The plant to check
     * @return bool True if plant has received sufficient additional resources
     */
    bool canProgress(Plant* plant) override;
};

#endif
