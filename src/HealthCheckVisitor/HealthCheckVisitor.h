#ifndef HEALTHCHECKVISITOR_H
#define HEALTHCHECKVISITOR_H

#include "src/CareVisitor/CareVisitor.h"
#include <vector>
#include <string>

class FlowerPlant;
class TreePlant;
class HerbPlant;
class GrassPlant;
class SucculentPlant;

class HealthCheckVisitor : public CareVisitor {
private:
    std::vector<std::string> plantReports;
    
    void checkPlantConditions(class Plant* plant, const std::string& emoji);

public:
    virtual ~HealthCheckVisitor() = default;
    
    // Concrete visit methods
    virtual void visitFlowerPlant(FlowerPlant* flower) override;
    virtual void visitTreePlant(TreePlant* tree) override;
    virtual void visitHerbPlant(HerbPlant* herb) override;
    virtual void visitGrassPlant(GrassPlant* grass) override;
    virtual void visitSucculentPlant(SucculentPlant* succulent) override;
    
    // Report methods
    void printReport();
    void clearReports();
    
    const std::vector<std::string>& getPlantReports() const { return plantReports; }
};

#endif