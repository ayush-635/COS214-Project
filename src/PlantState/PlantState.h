#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>

class Plant;

/**
 * @class PlantState
 * @brief Interface for plant growth states
 */
class PlantState {
public:
    virtual ~PlantState() = default;
    
    /**
     * @brief Handle state-specific behavior
     * @param plant The plant to handle
     */
    virtual void handle(Plant* plant) = 0;
    
    /**
     * @brief Get state name
     * @return std::string Name of the state
     */
    virtual std::string getName() const = 0;
    
    /**
     * @brief Check if plant can progress to next state
     * @param plant The plant to check
     * @return bool True if plant meets progression requirements
     */
    virtual bool canProgress(Plant* plant) = 0;
};

#endif
