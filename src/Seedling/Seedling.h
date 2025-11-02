#ifndef SEEDLING_H
#define SEEDLING_H

#include "../PlantState/PlantState.h"

/**
 * @class Seedling
 * @brief Initial growth state for all plants
 */
class Seedling : public PlantState {
public:
    /**
     * @brief Handle state behavior for seedling plants
     * @param plant The plant to handle
     */
    void handle(Plant* plant) override;

    /**
     * @brief Get the name of this state
     * @return std::string Always returns "Seedling"
     */
    std::string getName() const override { return "Seedling"; }

    /**
     * @brief Check if plant can progress to Growing state
     * @param plant The plant to check
     * @return bool True if plant has received sufficient resources
     */
    bool canProgress(Plant* plant) override;
};

#endif