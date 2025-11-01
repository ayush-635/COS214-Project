#ifndef HEALTHCHECKVISITOR_H
#define HEALTHCHECKVISITOR_H

#include "../CareVisitor/CareVisitor.h"
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
    int flowerCount;
    int treeCount;
    int herbCount;
    int grassCount;
    int succulentCount;
    int healthyCount;
    int unhealthyCount;
    
    void checkPlantConditions(class Plant* plant, const std::string& emoji);

public:
    HealthCheckVisitor();
    virtual ~HealthCheckVisitor() = default;
    
    // Concrete visit methods
    virtual void visitFlowerPlant(FlowerPlant* flower) override;
    virtual void visitTreePlant(TreePlant* tree) override;
    virtual void visitHerbPlant(HerbPlant* herb) override;
    virtual void visitGrassPlant(GrassPlant* grass) override;
    virtual void visitSucculentPlant(SucculentPlant* succulent) override;
    
    // Report methods
    void printReport();
    void displayReport();
    void clearReports();
    void reset();
    std::string getReport() const;
    
    const std::vector<std::string>& getPlantReports() const { return plantReports; }
};

#endif