#include "HealthCheckVisitor.h"
#include "../Plant/Plant.h"
#include "../FlowerPlant/FlowerPlant.h"
#include "../TreePlant/TreePlant.h"
#include "../HerbPlant/HerbPlant.h"
#include "../GrassPlant/GrassPlant.h"
#include "../SucculentPlant/SucculentPlant.h"
#include <iostream>
#include <sstream>

HealthCheckVisitor::HealthCheckVisitor() 
    : flowerCount(0), treeCount(0), herbCount(0), 
      grassCount(0), succulentCount(0),
      healthyCount(0), unhealthyCount(0) {
}

void HealthCheckVisitor::checkPlantConditions(Plant* plant, const std::string& emoji) {
    std::string state = plant->getStateName();
    
    // Check if plant is unhealthy
    bool isUnhealthy = (state == "Dying" || state == "Dead");
    
    if (isUnhealthy) {
        unhealthyCount++;
    } else {
        healthyCount++;
    }
    
    // Build report line
    std::ostringstream oss;
    oss << emoji << " " << plant->getName() << " - " << state;
    
    if (isUnhealthy) {
        oss << " ⚠️";
    } else {
        oss << " ✓";
    }
    
    plantReports.push_back(oss.str());
    
    // Print immediately for real-time feedback
    std::cout << "  " << oss.str() << std::endl;
}

void HealthCheckVisitor::visitFlowerPlant(FlowerPlant* flower) {
    flowerCount++;
    checkPlantConditions(flower, "🌸");
}

void HealthCheckVisitor::visitTreePlant(TreePlant* tree) {
    treeCount++;
    checkPlantConditions(tree, "🌳");
}

void HealthCheckVisitor::visitHerbPlant(HerbPlant* herb) {
    herbCount++;
    checkPlantConditions(herb, "🌿");
}

void HealthCheckVisitor::visitGrassPlant(GrassPlant* grass) {
    grassCount++;
    checkPlantConditions(grass, "🟢");
}

void HealthCheckVisitor::visitSucculentPlant(SucculentPlant* succulent) {
    succulentCount++;
    checkPlantConditions(succulent, "🌵");
}

void HealthCheckVisitor::printReport() {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║       📊 HEALTH SUMMARY 📊             ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    std::cout << "\n🌱 PLANT TYPES:" << std::endl;
    if (flowerCount > 0) std::cout << "   🌸 Flowers: " << flowerCount << std::endl;
    if (treeCount > 0) std::cout << "   🌳 Trees: " << treeCount << std::endl;
    if (herbCount > 0) std::cout << "   🌿 Herbs: " << herbCount << std::endl;
    if (grassCount > 0) std::cout << "   🟢 Grass: " << grassCount << std::endl;
    if (succulentCount > 0) std::cout << "   🌵 Succulents: " << succulentCount << std::endl;
    
    std::cout << "\n💚 HEALTH STATUS:" << std::endl;
    std::cout << "   ✅ Healthy: " << healthyCount << std::endl;
    std::cout << "   ❌ Unhealthy: " << unhealthyCount << std::endl;
    
    if (unhealthyCount > 0) {
        std::cout << "\n⚠️  WARNING: " << unhealthyCount << " plant(s) need attention!" << std::endl;
    } else if (healthyCount > 0) {
        std::cout << "\n🎉 All plants are healthy!" << std::endl;
    }
    
    std::cout << "════════════════════════════════════════" << std::endl;
}

void HealthCheckVisitor::displayReport() {
    printReport();
}

std::string HealthCheckVisitor::getReport() const {
    std::ostringstream oss;
    oss << "\n📊 HEALTH SUMMARY:\n";
    oss << "════════════════════════════════════════\n";
    
    if (flowerCount > 0) oss << "   🌸 Flowers: " << flowerCount << "\n";
    if (treeCount > 0) oss << "   🌳 Trees: " << treeCount << "\n";
    if (herbCount > 0) oss << "   🌿 Herbs: " << herbCount << "\n";
    if (grassCount > 0) oss << "   🟢 Grass: " << grassCount << "\n";
    if (succulentCount > 0) oss << "   🌵 Succulents: " << succulentCount << "\n";
    
    oss << "   ─────────────────────────────────────\n";
    oss << "   ✅ Healthy: " << healthyCount << "\n";
    oss << "   ❌ Unhealthy: " << unhealthyCount << "\n";
    
    return oss.str();
}

void HealthCheckVisitor::clearReports() {
    plantReports.clear();
}

void HealthCheckVisitor::reset() {
    plantReports.clear();
    flowerCount = 0;
    treeCount = 0;
    herbCount = 0;
    grassCount = 0;
    succulentCount = 0;
    healthyCount = 0;
    unhealthyCount = 0;
}