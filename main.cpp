#include "src/NurseryManager/NurseryManager.h"
#include "src/ConcreteSpaceBuilder/ConcreteSpaceBuilder.h"
#include "src/PlanterBox/PlanterBox.h"
#include "src/PlanterBoxCollection/PlanterBoxCollection.h"
#include "src/PlantDataFactory/PlantDataFactory.h"
#include "src/FlowerFactory/FlowerFactory.h"
#include "src/GrassFactory/GrassFactory.h"
#include "src/HerbFactory/HerbFactory.h"
#include "src/FlowerPlant/FlowerPlant.h"
#include "src/GrassPlant/GrassPlant.h"
#include "src/HerbPlant/HerbPlant.h"
#include "src/HealthCheckVisitor/HealthCheckVisitor.h"
#include <iostream>
#include <memory>
#include <vector>
#include <map>

class NurseryGame {
private:
    std::vector<PlantableArea*> spaces;
    std::map<std::string, PlantFactory*> factories;
    int dayCounter;
    double money;
    HealthCheckVisitor healthVisitor;

public:
    NurseryGame() : dayCounter(0), money(1000.0) {
        initializeGame();
    }

    ~NurseryGame() {
        for (auto space : spaces) {
            delete space;
        }
        for (auto factory : factories) {
            delete factory.second;
        }
    }

private:
    void initializeGame() {
        std::cout << "🌱 === WELCOME TO NURSERY MANAGER GAME === 🌱\n" << std::endl;
        
        // Initialize PlantDataFactory (Flyweight)
        PlantDataFactory::initializeFactory();
        
        // Initialize factories
        factories["flower"] = new FlowerFactory();
        factories["grass"] = new GrassFactory();
        factories["herb"] = new HerbFactory();
        
        // Create and register plant prototypes
        initializePlantPrototypes();
        
        std::cout << "Game initialized with $" << money << " starting capital\n" << std::endl;
    }

    void initializePlantPrototypes() {
        auto flowerData = PlantDataFactory::getPlantData("FlowerPlant");
        auto grassData = PlantDataFactory::getPlantData("GrassPlant");
        auto herbData = PlantDataFactory::getPlantData("HerbPlant");
        
        // Create prototype plants
        FlowerPlant* rosePrototype = new FlowerPlant("proto_rose", "Rose", flowerData);
        FlowerPlant* tulipPrototype = new FlowerPlant("proto_tulip", "Tulip", flowerData);
        GrassPlant* grassPrototype = new GrassPlant("proto_grass", "Lawn Grass", grassData);
        HerbPlant* basilPrototype = new HerbPlant("proto_basil", "Basil", herbData);
        HerbPlant* mintPrototype = new HerbPlant("proto_mint", "Mint", herbData);
        
        // Add to factories
        factories["flower"]->addPlantPrototype(rosePrototype);
        factories["flower"]->addPlantPrototype(tulipPrototype);
        factories["grass"]->addPlantPrototype(grassPrototype);
        factories["herb"]->addPlantPrototype(basilPrototype);
        factories["herb"]->addPlantPrototype(mintPrototype);
        
        // Clean up prototypes
        delete rosePrototype;
        delete tulipPrototype;
        delete grassPrototype;
        delete basilPrototype;
        delete mintPrototype;
        
        std::cout << "Registered plant types: Rose, Tulip, Lawn Grass, Basil, Mint\n" << std::endl;
    }

    void displayMainMenu() {
        std::cout << "\n=== DAY " << dayCounter << " | Money: $" << money << " ===" << std::endl;
        std::cout << "1. Build New Space" << std::endl;
        std::cout << "2. View All Spaces" << std::endl;
        std::cout << "3. Add Plants to Space" << std::endl;
        std::cout << "4. Care for Plants" << std::endl;
        std::cout << "5. Advance Day (Update Plants)" << std::endl;
        std::cout << "6. Sell Ready Plants" << std::endl;
        std::cout << "7. Game Status" << std::endl;
        std::cout << "8. Health Check (Visitor Pattern)" << std::endl;  // NEW
        std::cout << "9. Exit Game" << std::endl;
        std::cout << "Choose an option: ";
    }

    void buildNewSpace() {
        std::cout << "\n=== BUILD NEW SPACE ===" << std::endl;
        std::cout << "1. Small Space (2 boxes) - $50" << std::endl;
        std::cout << "2. Medium Space (4 boxes) - $80" << std::endl;
        std::cout << "3. Big Space (nested) - $120" << std::endl;
        std::cout << "Choose space type: ";
        
        int choice;
        std::cin >> choice;
        
        if (money < 50) {
            std::cout << "❌ Not enough money to build space!" << std::endl;
            return;
        }
        
        NurseryManager manager;
        ConcreteSpaceBuilder* builder = new ConcreteSpaceBuilder();
        manager.setBuilder(builder);
        
        PlantableArea* newSpace = nullptr;
        int cost = 0;
        
        switch (choice) {
            case 1:
                newSpace = manager.constructSmallSpace();
                cost = 50;
                break;
            case 2:
                newSpace = manager.constructMediumSpace();
                cost = 80;
                break;
            case 3:
                newSpace = manager.constructBigSpace();
                cost = 120;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                delete builder;
                return;
        }
        
        if (newSpace) {
            money -= cost;
            spaces.push_back(newSpace);
            std::cout << "✅ Space built successfully! Cost: $" << cost << std::endl;
            newSpace->display();
        }
        
        delete builder;
    }

    void viewAllSpaces() {
        std::cout << "\n=== YOUR SPACES ===" << std::endl;
        if (spaces.empty()) {
            std::cout << "No spaces built yet!" << std::endl;
            return;
        }
        
        for (size_t i = 0; i < spaces.size(); ++i) {
            std::cout << "\n--- Space " << (i + 1) << " ---" << std::endl;
            spaces[i]->display();
            
            // Show plant states in this space
            showPlantStates(spaces[i]);
        }
    }

    void showPlantStates(PlantableArea* space) {
        std::cout << "Plant States in this space:" << std::endl;
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    std::string stateEmoji = "🌱"; // Seedling
                    if (plant->getStateName() == "Growing") stateEmoji = "🌿";
                    else if (plant->getStateName() == "Mature") stateEmoji = "🌳";
                    else if (plant->getStateName() == "ReadyToSell") stateEmoji = "💰";
                    else if (plant->getStateName() == "Dying") stateEmoji = "⚠️";
                    else if (plant->getStateName() == "Dead") stateEmoji = "💀";
                    
                    std::cout << "  " << stateEmoji << " " << plant->getName() 
                              << " - " << plant->getStateName() << std::endl;
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                showPlantStates(collection);
            }
        }
    }

    void addPlantsToSpace() {
        if (spaces.empty()) {
            std::cout << "❌ No spaces available! Build a space first." << std::endl;
            return;
        }
        
        std::cout << "\n=== ADD PLANTS ===" << std::endl;
        std::cout << "Available plants:" << std::endl;
        std::cout << "1. Rose - $15" << std::endl;
        std::cout << "2. Tulip - $12" << std::endl;
        std::cout << "3. Lawn Grass - $8" << std::endl;
        std::cout << "4. Basil - $10" << std::endl;
        std::cout << "5. Mint - $10" << std::endl;
        
        int plantChoice, spaceChoice;
        std::cout << "Choose plant type: ";
        std::cin >> plantChoice;
        std::cout << "Choose space (1-" << spaces.size() << "): ";
        std::cin >> spaceChoice;
        
        if (spaceChoice < 1 || spaceChoice > spaces.size()) {
            std::cout << "Invalid space choice!" << std::endl;
            return;
        }
        
        Plant* newPlant = nullptr;
        int cost = 0;
        std::string plantName;
        
        switch (plantChoice) {
            case 1: newPlant = factories["flower"]->createPlant("Rose"); cost = 15; plantName = "Rose"; break;
            case 2: newPlant = factories["flower"]->createPlant("Tulip"); cost = 12; plantName = "Tulip"; break;
            case 3: newPlant = factories["grass"]->createPlant("Lawn Grass"); cost = 8; plantName = "Lawn Grass"; break;
            case 4: newPlant = factories["herb"]->createPlant("Basil"); cost = 10; plantName = "Basil"; break;
            case 5: newPlant = factories["herb"]->createPlant("Mint"); cost = 10; plantName = "Mint"; break;
            default: std::cout << "Invalid plant choice!" << std::endl; return;
        }
        
        if (money < cost) {
            std::cout << "❌ Not enough money to buy " << plantName << "!" << std::endl;
            delete newPlant;
            return;
        }
        
        if (newPlant) {
            // Set unique ID
            newPlant->setID(plantName + "_" + std::to_string(dayCounter));
            
            // Add to first available box in the space
            addPlantToFirstAvailableBox(spaces[spaceChoice - 1], newPlant);
            money -= cost;
            std::cout << "✅ " << plantName << " planted successfully! Cost: $" << cost << std::endl;
            std::cout << "   Initial state: " << newPlant->getStateName() << std::endl;
        } else {
            std::cout << "❌ Failed to create plant!" << std::endl;
        }
    }

    void addPlantToFirstAvailableBox(PlantableArea* space, Plant* plant) {
        // Try to find first available planter box
        for (int i = 0; i < 10; ++i) { // Reasonable limit
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                box->populate(plant);
                return;
            }
            
            // If it's a collection, search recursively
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                addPlantToFirstAvailableBox(collection, plant);
                return;
            }
        }
        
        std::cout << "❌ No available space for new plant!" << std::endl;
        delete plant;
    }

    void careForPlants() {
        if (spaces.empty()) {
            std::cout << "❌ No spaces with plants!" << std::endl;
            return;
        }
        
        std::cout << "\n=== PLANT CARE ===" << std::endl;
        std::cout << "1. Water Plants ($1 per space)" << std::endl;
        std::cout << "2. Fertilize Plants ($3 per space)" << std::endl;
        std::cout << "Choose action: ";
        
        int choice, spaceChoice;
        std::cin >> choice;
        std::cout << "Choose space (1-" << spaces.size() << "): ";
        std::cin >> spaceChoice;
        
        if (spaceChoice < 1 || spaceChoice > spaces.size()) {
            std::cout << "Invalid space choice!" << std::endl;
            return;
        }
        
        int cost = (choice == 1) ? 1 : 3;
        if (money < cost) {
            std::cout << "❌ Not enough money for this action!" << std::endl;
            return;
        }
        
        if (choice == 1) {
            spaces[spaceChoice - 1]->water(1, 0); // Water all plants in first box
            money -= cost;
            std::cout << "💧 Plants watered! Cost: $" << cost << std::endl;
        } else if (choice == 2) {
            spaces[spaceChoice - 1]->giveFertilizer(1, 0); // Fertilize all plants in first box
            money -= cost;
            std::cout << "🌱 Plants fertilized! Cost: $" << cost << std::endl;
        }
    }

    void advanceDay() {
        std::cout << "\n=== ADVANCING TO DAY " << (dayCounter + 1) << " ===" << std::endl;
        dayCounter++;
        
        // Update all plants in all spaces (State Pattern)
        for (auto space : spaces) {
            updatePlantsInSpace(space);
        }
        
        std::cout << "✅ Day advanced! All plants have been updated." << std::endl;
        
        // Show state changes
        showStateChanges();
    }

    void updatePlantsInSpace(PlantableArea* space) {
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                // Get plants and update them (State Pattern)
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    std::string oldState = plant->getStateName();
                    plant->update();
                    std::string newState = plant->getStateName();
                    
                    // Log state transitions
                    if (oldState != newState) {
                        std::cout << "🔄 " << plant->getName() << " changed from " 
                                  << oldState << " to " << newState << std::endl;
                    }
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                updatePlantsInSpace(collection);
            }
        }
    }

    void showStateChanges() {
        int seedlings = 0, growing = 0, mature = 0, ready = 0, dying = 0, dead = 0;
        
        for (auto space : spaces) {
            countPlantStates(space, seedlings, growing, mature, ready, dying, dead);
        }
        
        std::cout << "\n📊 Current Plant States:" << std::endl;
        std::cout << "🌱  Seedlings: " << seedlings << std::endl;
        std::cout << "🌿  Growing: " << growing << std::endl;
        std::cout << "🌳  Mature: " << mature << std::endl;
        std::cout << "💰  Ready to Sell: " << ready << std::endl;
        std::cout << "⚠️   Dying: " << dying << std::endl;
        std::cout << "💀  Dead: " << dead << std::endl;
    }

    void countPlantStates(PlantableArea* space, int& seedlings, int& growing, int& mature, 
                         int& ready, int& dying, int& dead) {
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    std::string state = plant->getStateName();
                    if (state == "Seedling") seedlings++;
                    else if (state == "Growing") growing++;
                    else if (state == "Mature") mature++;
                    else if (state == "ReadyToSell") ready++;
                    else if (state == "Dying") dying++;
                    else if (state == "Dead") dead++;
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                countPlantStates(collection, seedlings, growing, mature, ready, dying, dead);
            }
        }
    }

    void sellReadyPlants() {
        std::cout << "\n=== SELL READY PLANTS ===" << std::endl;
        double totalEarnings = 0;
        int plantsSold = 0;
        
        for (auto space : spaces) {
            auto earnings = harvestReadyPlantsFromSpace(space);
            totalEarnings += earnings.first;
            plantsSold += earnings.second;
        }
        
        money += totalEarnings;
        std::cout << "💰 Sold " << plantsSold << " plants for $" << totalEarnings << std::endl;
    }

    std::pair<double, int> harvestReadyPlantsFromSpace(PlantableArea* space) {
        double earnings = 0;
        int count = 0;
        
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    if (plant->getStateName() == "ReadyToSell") {
                        // Calculate value based on plant type and care
                        double value = 20.0 + (plant->getWaterReceived() * 0.5) + (plant->getFertilizerReceived() * 0.8);
                        earnings += value;
                        count++;
                        
                        // Remove plant (in real implementation, you'd actually remove it)
                        std::cout << "✅ Sold " << plant->getName() << " for $" << value << std::endl;
                    }
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                auto result = harvestReadyPlantsFromSpace(collection);
                earnings += result.first;
                count += result.second;
            }
        }
        
        return {earnings, count};
    }

    void gameStatus() {
        std::cout << "\n=== GAME STATUS ===" << std::endl;
        std::cout << "Day: " << dayCounter << std::endl;
        std::cout << "Money: $" << money << std::endl;
        std::cout << "Spaces: " << spaces.size() << std::endl;
        
        int totalPlants = 0;
        int readyPlants = 0;
        
        for (auto space : spaces) {
            auto stats = getSpaceStats(space);
            totalPlants += stats.first;
            readyPlants += stats.second;
        }
        
        std::cout << "Total Plants: " << totalPlants << std::endl;
        std::cout << "Ready to Sell: " << readyPlants << std::endl;
        std::cout << "Plants in progress: " << (totalPlants - readyPlants) << std::endl;
        
        // Show state distribution
        showStateChanges();
    }

    std::pair<int, int> getSpaceStats(PlantableArea* space) {
        int total = 0;
        int ready = 0;
        
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                total += plants.size();
                for (auto plant : plants) {
                    if (plant->getStateName() == "ReadyToSell") {
                        ready++;
                    }
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                auto stats = getSpaceStats(collection);
                total += stats.first;
                ready += stats.second;
            }
        }
        
        return {total, ready};
    }

    // NEW: Health Check using Visitor Pattern
    void healthCheck() {
        std::cout << "\n=== PLANT HEALTH CHECK (Visitor Pattern) ===" << std::endl;
        
        if (spaces.empty()) {
            std::cout << "No plants to check!" << std::endl;
            return;
        }
        
        healthVisitor.clearReports();
        
        // Visit all plants using the Visitor pattern
        for (auto space : spaces) {
            visitPlantsInSpace(space);
        }
        
        // Print the health report
        healthVisitor.printReport();
    }

    void visitPlantsInSpace(PlantableArea* space) {
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    // Use Visitor pattern to check plant health
                    plant->accept(healthVisitor);
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                visitPlantsInSpace(collection);
            }
        }
    }

public:
    void run() {
        int choice;
        
        do {
            displayMainMenu();
            std::cin >> choice;
            
            switch (choice) {
                case 1: buildNewSpace(); break;
                case 2: viewAllSpaces(); break;
                case 3: addPlantsToSpace(); break;
                case 4: careForPlants(); break;
                case 5: advanceDay(); break;
                case 6: sellReadyPlants(); break;
                case 7: gameStatus(); break;
                case 8: healthCheck(); break;  // NEW
                case 9: std::cout << "Thanks for playing!" << std::endl; break;
                default: std::cout << "Invalid choice!" << std::endl;
            }
            
        } while (choice != 9);
    }
};

int main() {
    NurseryGame game;
    game.run();
    return 0;
}