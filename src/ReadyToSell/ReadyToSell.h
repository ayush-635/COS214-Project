#ifndef READYTOSELL_H
#define READYTOSELL_H

#include "../PlantState/PlantState.h"

/**
 * @class ReadyToSell
 * @brief Final growth state representing plants ready for sale
 */
class ReadyToSell : public PlantState {
public:
    /**
     * @brief Handle state behavior for ready-to-sell plants
     * @param plant The plant to handle
     */
    void handle(Plant* plant) override;
    
    /**
     * @brief Get the name of this state
     * @return std::string Always returns "ReadyToSell"
     */
    std::string getName() const override { return "ReadyToSell"; }
    
    /**
     * @brief Check if plant can progress from this state
     * @param plant The plant to check
     * @return bool Always returns false (ready-to-sell plants don't progress)
     */
    bool canProgress(Plant* plant) override;
};

#endif
