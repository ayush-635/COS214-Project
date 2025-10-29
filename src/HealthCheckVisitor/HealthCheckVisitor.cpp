#include "HealthCheckVisitor.h"
#include "../Plant/Plant.h"
#include "../FlowerPlant/FlowerPlant.h"
#include "../TreePlant/TreePlant.h"
#include "../HerbPlant/HerbPlant.h"
#include "../GrassPlant/GrassPlant.h"
#include "../SucculentPlant/SucculentPlant.h"
#include <iostream>

void HealthCheckVisitor::checkPlantConditions(Plant* plant, const std::string& emoji) {
    if (plant->isDead()) {
        plantReports.push_back(emoji + " " + plant->getName() + " 💀 DEAD");
        return;
    }
    
    if (plant->isDying()) {
        std::string report = emoji + " " + plant->getName() + " ⚠️ DYING";
        
        // Show what the dying plant needs
        if (plant->needsWater() && plant->needsFertilizer()) {
            report += " - Needs BOTH Water and Fertilizer!";
        } else if (plant->needsWater()) {
            report += " - Needs Water!";
        } else if (plant->needsFertilizer()) {
            report += " - Needs Fertilizer!";
        }
        
        // Show danger level
        int waterTicksUntilDeath = plant->getWaterDeathTime() - plant->getTicksWithoutWater();
        int fertilizerTicksUntilDeath = plant->getFertilizerDeathTime() - plant->getTicksWithoutFertilizer();
        int ticksUntilDeath = std::min(waterTicksUntilDeath, fertilizerTicksUntilDeath);
        
        report += " (Dying in " + std::to_string(ticksUntilDeath) + " ticks!)";
        
        plantReports.push_back(report);
        return;
    }
    
    std::string report = emoji + " " + plant->getName() + " [" + plant->getStateName() + "]";
    


    if (plant->needsWater()) {
        report += " | 💧 Needs Water";
        if (plant->isInDanger()) {
            int ticksUntilDeath = plant->getWaterDeathTime() - plant->getTicksWithoutWater();
            report += " (Dying in " + std::to_string(ticksUntilDeath) + " ticks!)";
        }
    } else {
        int ticksUntilNextWater = plant->getWaterInterval() - plant->getTicksWithoutWater();
        report += " | 💧 Watered (" + std::to_string(ticksUntilNextWater) + " ticks)";
    }
    


    if (plant->needsFertilizer()) {
        report += " | 🌱 Needs Fertilizer";
        if (plant->isInDanger()) {
            int ticksUntilDeath = plant->getFertilizerDeathTime() - plant->getTicksWithoutFertilizer();
            report += " (Dying in " + std::to_string(ticksUntilDeath) + " ticks!)";
        }
    } else {
        int ticksUntilNextFertilizer = plant->getFertilizerInterval() - plant->getTicksWithoutFertilizer();
        report += " | 🌱 Fertilized (" + std::to_string(ticksUntilNextFertilizer) + " ticks)";
    }
    
    report += " | Needs: " + std::to_string(plant->getWaterRemaining()) + "W " + 
              std::to_string(plant->getFertilizerRemaining()) + "F for next state";
    
    plantReports.push_back(report);
}


void HealthCheckVisitor::visitFlowerPlant(FlowerPlant* flower) {
    checkPlantConditions(flower, "🌸");
}

void HealthCheckVisitor::visitTreePlant(TreePlant* tree) {
    checkPlantConditions(tree, "🌳");
}

void HealthCheckVisitor::visitHerbPlant(HerbPlant* herb) {
    checkPlantConditions(herb, "🌿");
}

void HealthCheckVisitor::visitGrassPlant(GrassPlant* grass) {
    checkPlantConditions(grass, "🟢");
}

void HealthCheckVisitor::visitSucculentPlant(SucculentPlant* succulent) {
    checkPlantConditions(succulent, "🌵");
}

void HealthCheckVisitor::printReport() {
    std::cout << "\n=== PLANT STATUS ===" << std::endl;
    for (const auto& report : plantReports) {
        std::cout << "• " << report << std::endl;
    }
    std::cout << "====================\n" << std::endl;
}

void HealthCheckVisitor::clearReports() {
    plantReports.clear();

}