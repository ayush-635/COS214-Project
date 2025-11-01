#ifndef HEALTHCHECKVISITOR_H
#define HEALTHCHECKVISITOR_H

#include "../CareVisitor/CareVisitor.h"
#include <vector>
#include <string>

// Forward declarations
class FlowerPlant;
class TreePlant;
class HerbPlant;
class GrassPlant;
class SucculentPlant;

/**
 * @class HealthCheckVisitor
 * @brief Concrete visitor for checking plant health conditions
 */
class HealthCheckVisitor : public CareVisitor {
private:
    std::vector<std::string> plantReports; ///< Collection of generated plant reports
    
    /**
     * @brief Check conditions for a specific plant and generate report
     * @param plant The plant to check
     * @param emoji The emoji to use for this plant type in reports
     */
    void checkPlantConditions(class Plant* plant, const std::string& emoji);

public:
    virtual ~HealthCheckVisitor() = default;
    
    // Concrete visit methods
    
    /**
     * @brief Visit and check health of a FlowerPlant
     * @param flower The flower plant to check
     */
    virtual void visitFlowerPlant(FlowerPlant* flower) override;
    
    /**
     * @brief Visit and check health of a TreePlant
     * @param tree The tree plant to check
     */
    virtual void visitTreePlant(TreePlant* tree) override;
    
    /**
     * @brief Visit and check health of a HerbPlant
     * @param herb The herb plant to check
     */
    virtual void visitHerbPlant(HerbPlant* herb) override;
    
    /**
     * @brief Visit and check health of a GrassPlant
     * @param grass The grass plant to check
     */
    virtual void visitGrassPlant(GrassPlant* grass) override;
    
    /**
     * @brief Visit and check health of a SucculentPlant
     * @param succulent The succulent plant to check
     */
    virtual void visitSucculentPlant(SucculentPlant* succulent) override;
    
    // Report methods
    
    /**
     * @brief Print all generated plant reports to console
     */
    void printReport();
    
    /**
     * @brief Clear all stored plant reports
     */
    void clearReports();
    
    /**
     * @brief Get all plant reports
     * @return const std::vector<std::string>& Reference to plant reports collection
     */
    const std::vector<std::string>& getPlantReports() const { return plantReports; }
};

#endif
