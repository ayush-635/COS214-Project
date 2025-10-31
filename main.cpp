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
#include "src/WaterPlantCommand/WaterPlantCommand.h"
#include "src/GiveFertilizerCommand/GiveFertilizerCommand.h"
#include "src/PlantSeedCommand/PlantSeedCommand.h"
#include "src/RemovePlantCommand/RemovePlantCommand.h"
#include "src/LightWateringStrategy/LightWateringStrategy.h"
#include "src/IntermediateWateringStrategy/IntermediateWateringStrategy.h"
#include "src/HeavyWateringStrategy/HeavyWateringStrategy.h"
#include "src/BankAccount/BankAccount.h"
#include "src/BuyAssetsCommand/BuyAssetsCommand.h"
#include "src/SaleCommand/SaleCommand.h"
#include "src/TransactionManager/TransactionManager.h"
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <queue>

class NurseryGame {
private:
    std::vector<PlantableArea*> spaces;
    std::map<std::string, PlantFactory*> factories;
    std::queue<Duty*> commandQueue; // Command Pattern: Queue of duties (for plant operations)
    BankAccount* bankAccount; // Singleton: Bank account
    TransactionManager transactionManager; // Command Pattern: For financial transactions
    int dayCounter;
    HealthCheckVisitor healthVisitor;
    WateringStrategy* currentWateringStrategy;

public:
    NurseryGame() : dayCounter(0), currentWateringStrategy(nullptr) {
        initializeGame();
    }

    ~NurseryGame() {
        for (auto space : spaces) {
            delete space;
        }
        for (auto factory : factories) {
            delete factory.second;
        }
        while (!commandQueue.empty()) {
            delete commandQueue.front();
            commandQueue.pop();
        }
        delete currentWateringStrategy;
    }

private:
    void initializeGame() {
        std::cout << "🌱 === WELCOME TO NURSERY MANAGER GAME === 🌱\n" << std::endl;
        
        // Initialize BankAccount singleton
        bankAccount = BankAccount::getInstance();
        bankAccount->deposit(1000.0, "Starting capital");
        
        // Initialize PlantDataFactory (Flyweight)
        PlantDataFactory::initializeFactory();
        
        // Initialize factories
        factories["flower"] = new FlowerFactory();
        factories["grass"] = new GrassFactory();
        factories["herb"] = new HerbFactory();
        
        // Set default watering strategy (Strategy Pattern)
        currentWateringStrategy = new IntermediateWateringStrategy();
        
        // Create and register plant prototypes
        initializePlantPrototypes();
        
        std::cout << "Game initialized with R" << bankAccount->getBalance() << " starting capital\n" << std::endl;
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
        std::cout << "\n=== DAY " << dayCounter << " | Balance: R" << bankAccount->getBalance() << " ===" << std::endl;
        std::cout << "1. Build New Space (Builder + Banking)" << std::endl;
        std::cout << "2. View All Spaces" << std::endl;
        std::cout << "3. Add Plants to Space (Command)" << std::endl;
        std::cout << "4. Care for Plants (Command + Strategy)" << std::endl;
        std::cout << "5. Remove Plants (Command)" << std::endl;
        std::cout << "6. Execute Plant Command Queue" << std::endl;
        std::cout << "7. Change Watering Strategy" << std::endl;
        std::cout << "8. Advance Day (Update Plants)" << std::endl;
        std::cout << "9. Sell Ready Plants (Banking)" << std::endl;
        std::cout << "10. Game Status" << std::endl;
        std::cout << "11. Health Check (Visitor Pattern)" << std::endl;
        std::cout << "12. View Bank Account Log (Singleton)" << std::endl;
        std::cout << "13. Execute Financial Transactions (Command)" << std::endl;
        std::cout << "14. Exit Game" << std::endl;
        std::cout << "Choose an option: ";
    }

    void buildNewSpace() {
        std::cout << "\n=== BUILD NEW SPACE (Builder + Banking) ===" << std::endl;
        std::cout << "1. Small Space (2 boxes) - R50" << std::endl;
        std::cout << "2. Medium Space (4 boxes) - R80" << std::endl;
        std::cout << "3. Big Space (nested) - R120" << std::endl;
        std::cout << "Choose space type: ";
        
        int choice;
        std::cin >> choice;
        
        double cost = 0;
        std::string spaceName;
        
        switch (choice) {
            case 1: cost = 50; spaceName = "Small Space"; break;
            case 2: cost = 80; spaceName = "Medium Space"; break;
            case 3: cost = 120; spaceName = "Big Space"; break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                return;
        }
        
        if (bankAccount->getBalance() < cost) {
            std::cout << "❌ Not enough money to build space!" << std::endl;
            std::cout << "Current balance: R" << bankAccount->getBalance() << std::endl;
            std::cout << "Required: R" << cost << std::endl;
            return;
        }
        
        // Create purchase command and add to transaction manager
        BuyAssetsCommand* purchaseCommand = new BuyAssetsCommand(bankAccount, spaceName, cost);
        transactionManager.addCommand(purchaseCommand);
        
        std::cout << "💰 Transaction queued: Purchase " << spaceName << " for R" << cost << std::endl;
        std::cout << "Execute financial transactions (option 13) to complete purchase.\n" << std::endl;
        
        NurseryManager manager;
        ConcreteSpaceBuilder* builder = new ConcreteSpaceBuilder();
        manager.setBuilder(builder);
        
        PlantableArea* newSpace = nullptr;
        
        switch (choice) {
            case 1:
                newSpace = manager.constructSmallSpace();
                break;
            case 2:
                newSpace = manager.constructMediumSpace();
                break;
            case 3:
                newSpace = manager.constructBigSpace();
                break;
        }
        
        if (newSpace) {
            spaces.push_back(newSpace);
            std::cout << "✅ Space construction planned!" << std::endl;
            newSpace->display();
        }
        
        delete builder;
    }

    void addPlantsWithCommand() {
        if (spaces.empty()) {
            std::cout << "❌ No spaces available! Build a space first." << std::endl;
            return;
        }
        
        std::cout << "\n=== ADD PLANTS (Command Pattern + Banking) ===" << std::endl;
        std::cout << "Available plants:" << std::endl;
        std::cout << "1. Rose - R15" << std::endl;
        std::cout << "2. Tulip - R12" << std::endl;
        std::cout << "3. Lawn Grass - R8" << std::endl;
        std::cout << "4. Basil - R10" << std::endl;
        std::cout << "5. Mint - R10" << std::endl;
        
        int plantChoice, spaceChoice, boxIndex;
        std::cout << "Choose plant type: ";
        std::cin >> plantChoice;
        std::cout << "Choose space (1-" << spaces.size() << "): ";
        std::cin >> spaceChoice;
        std::cout << "Choose box index (0-9): ";
        std::cin >> boxIndex;
        
        if (spaceChoice < 1 || spaceChoice > spaces.size()) {
            std::cout << "Invalid space choice!" << std::endl;
            return;
        }
        
        Plant* newPlant = nullptr;
        double cost = 0;
        std::string plantName;
        
        switch (plantChoice) {
            case 1: newPlant = factories["flower"]->createPlant("Rose"); cost = 15; plantName = "Rose"; break;
            case 2: newPlant = factories["flower"]->createPlant("Tulip"); cost = 12; plantName = "Tulip"; break;
            case 3: newPlant = factories["grass"]->createPlant("Lawn Grass"); cost = 8; plantName = "Lawn Grass"; break;
            case 4: newPlant = factories["herb"]->createPlant("Basil"); cost = 10; plantName = "Basil"; break;
            case 5: newPlant = factories["herb"]->createPlant("Mint"); cost = 10; plantName = "Mint"; break;
            default: std::cout << "Invalid plant choice!" << std::endl; return;
        }
        
        if (bankAccount->getBalance() < cost) {
            std::cout << "❌ Not enough money to buy " << plantName << "!" << std::endl;
            std::cout << "Current balance: R" << bankAccount->getBalance() << std::endl;
            std::cout << "Required: R" << cost << std::endl;
            delete newPlant;
            return;
        }
        
        if (newPlant) {
            newPlant->setID(plantName + "_" + std::to_string(dayCounter));
            
            // Create purchase command for the plant
            BuyAssetsCommand* plantPurchase = new BuyAssetsCommand(bankAccount, plantName + " seed", cost);
            transactionManager.addCommand(plantPurchase);
            
            // Create and queue plant command
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceChoice - 1]);
            if (collection) {
                PlantSeedCommand* plantCommand = new PlantSeedCommand(collection, newPlant, boxIndex);
                commandQueue.push(plantCommand);
                std::cout << "✅ Plant command queued for " << plantName << "!" << std::endl;
                std::cout << "💰 Purchase transaction queued: R" << cost << std::endl;
                std::cout << "   Plant commands in queue: " << commandQueue.size() << std::endl;
            } else {
                std::cout << "❌ Invalid space type for command!" << std::endl;
                delete newPlant;
            }
        }
    }

    void careForPlantsWithCommands() {
        if (spaces.empty()) {
            std::cout << "❌ No spaces with plants!" << std::endl;
            return;
        }
        
        std::cout << "\n=== PLANT CARE (Command + Strategy + Banking) ===" << std::endl;
        std::cout << "1. Water Plants (Current Strategy) - R1" << std::endl;
        std::cout << "2. Fertilize Plants - R3" << std::endl;
        std::cout << "Choose action: ";
        
        int choice, spaceChoice, boxIndex;
        std::cin >> choice;
        std::cout << "Choose space (1-" << spaces.size() << "): ";
        std::cin >> spaceChoice;
        std::cout << "Choose box index (0-9): ";
        std::cin >> boxIndex;
        
        if (spaceChoice < 1 || spaceChoice > spaces.size()) {
            std::cout << "Invalid space choice!" << std::endl;
            return;
        }
        
        double cost = (choice == 1) ? 1 : 3;
        std::string actionName = (choice == 1) ? "Water" : "Fertilizer";
        
        if (bankAccount->getBalance() < cost) {
            std::cout << "❌ Not enough money for this action!" << std::endl;
            std::cout << "Current balance: R" << bankAccount->getBalance() << std::endl;
            std::cout << "Required: R" << cost << std::endl;
            return;
        }
        
        PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceChoice - 1]);
        if (!collection) {
            std::cout << "❌ Invalid space type for command!" << std::endl;
            return;
        }
        
        // Queue purchase transaction
        BuyAssetsCommand* resourcePurchase = new BuyAssetsCommand(bankAccount, actionName, cost);
        transactionManager.addCommand(resourcePurchase);
        
        if (choice == 1) {
            // Water command with current strategy
            WaterPlantCommand* waterCommand = new WaterPlantCommand(collection, currentWateringStrategy, boxIndex);
            commandQueue.push(waterCommand);
            std::cout << "💧 Water command queued!" << std::endl;
        } else if (choice == 2) {
            // Fertilize command
            GiveFertilizerCommand* fertilizeCommand = new GiveFertilizerCommand(collection, 1, boxIndex);
            commandQueue.push(fertilizeCommand);
            std::cout << "🌱 Fertilize command queued!" << std::endl;
        }
        
        std::cout << "💰 Resource purchase queued: R" << cost << std::endl;
        std::cout << "   Plant commands in queue: " << commandQueue.size() << std::endl;
    }

    void removePlantsWithCommand() {
        if (spaces.empty()) {
            std::cout << "❌ No spaces with plants!" << std::endl;
            return;
        }
        
        std::cout << "\n=== REMOVE PLANTS (Command Pattern) ===" << std::endl;
        std::cout << "Choose space (1-" << spaces.size() << "): ";
        int spaceChoice, boxIndex;
        std::cin >> spaceChoice;
        std::cout << "Choose box index (0-9): ";
        std::cin >> boxIndex;
        
        if (spaceChoice < 1 || spaceChoice > spaces.size()) {
            std::cout << "Invalid space choice!" << std::endl;
            return;
        }
        
        // Find a plant to remove
        PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceChoice - 1]);
        if (!collection) {
            std::cout << "❌ Invalid space type for command!" << std::endl;
            return;
        }
        
        PlantableArea* box = collection->getChild(boxIndex);
        PlanterBox* planterBox = dynamic_cast<PlanterBox*>(box);
        if (planterBox && !planterBox->getPlants().empty()) {
            Plant* plantToRemove = planterBox->getPlants()[0]; // Remove first plant
            RemovePlantCommand* removeCommand = new RemovePlantCommand(collection, plantToRemove, boxIndex);
            commandQueue.push(removeCommand);
            std::cout << "🗑️ Remove plant command queued!" << std::endl;
            std::cout << "   Commands in queue: " << commandQueue.size() << std::endl;
        } else {
            std::cout << "❌ No plants found in selected box!" << std::endl;
        }
    }

    void executeCommandQueue() {
        std::cout << "\n=== EXECUTING PLANT COMMAND QUEUE ===" << std::endl;
        
        if (commandQueue.empty()) {
            std::cout << "No plant commands in queue!" << std::endl;
            return;
        }
        
        int commandsExecuted = 0;
        while (!commandQueue.empty()) {
            Duty* command = commandQueue.front();
            command->executeDuty();
            delete command;
            commandQueue.pop();
            commandsExecuted++;
        }
        
        std::cout << "✅ Executed " << commandsExecuted << " plant commands!" << std::endl;
    }

    void executeFinancialTransactions() {
        std::cout << "\n=== EXECUTING FINANCIAL TRANSACTIONS (Command Pattern) ===" << std::endl;
        
        if (transactionManager.commands.empty()) {
            std::cout << "No pending financial transactions!" << std::endl;
            return;
        }
        
        int commandCount = transactionManager.commands.size();
        double balanceBefore = bankAccount->getBalance();
        
        std::cout << "Executing " << commandCount << " transaction(s)..." << std::endl;
        transactionManager.executeCommands();
        
        double balanceAfter = bankAccount->getBalance();
        std::cout << "\n✅ Transactions completed!" << std::endl;
        std::cout << "Balance before: R" << balanceBefore << std::endl;
        std::cout << "Balance after: R" << balanceAfter << std::endl;
        std::cout << "Change: R" << (balanceAfter - balanceBefore) << std::endl;
    }

    void changeWateringStrategy() {
        std::cout << "\n=== CHANGE WATERING STRATEGY ===" << std::endl;
        std::cout << "1. Light Watering (1 unit)" << std::endl;
        std::cout << "2. Intermediate Watering (3 units)" << std::endl;
        std::cout << "3. Heavy Watering (5 units)" << std::endl;
        std::cout << "Choose strategy: ";
        
        int choice;
        std::cin >> choice;
        
        delete currentWateringStrategy; // Clean up old strategy
        
        switch (choice) {
            case 1:
                currentWateringStrategy = new LightWateringStrategy();
                std::cout << "✅ Set to Light Watering Strategy" << std::endl;
                break;
            case 2:
                currentWateringStrategy = new IntermediateWateringStrategy();
                std::cout << "✅ Set to Intermediate Watering Strategy" << std::endl;
                break;
            case 3:
                currentWateringStrategy = new HeavyWateringStrategy();
                std::cout << "✅ Set to Heavy Watering Strategy" << std::endl;
                break;
            default:
                currentWateringStrategy = new IntermediateWateringStrategy();
                std::cout << "❌ Invalid choice, using Intermediate" << std::endl;
                break;
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
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    std::string oldState = plant->getStateName();
                    plant->update();
                    std::string newState = plant->getStateName();
                    
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
        std::cout << "🌱 Seedlings: " << seedlings << std::endl;
        std::cout << "🌿 Growing: " << growing << std::endl;
        std::cout << "🌳 Mature: " << mature << std::endl;
        std::cout << "💰 Ready to Sell: " << ready << std::endl;
        std::cout << "⚠️  Dying: " << dying << std::endl;
        std::cout << "💀 Dead: " << dead << std::endl;
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
        std::cout << "\n=== SELL READY PLANTS (Banking + SaleCommand) ===" << std::endl;
        
        int plantsSold = 0;
        double totalRevenue = 0;
        
        for (auto space : spaces) {
            sellPlantsInSpace(space, plantsSold, totalRevenue);
        }
        
        if (plantsSold > 0) {
            // Note: This would normally create SaleCommand with Order object
            // For now, just deposit directly
            bankAccount->deposit(totalRevenue, "Sold " + std::to_string(plantsSold) + " plants");
            
            std::cout << "✅ Sold " << plantsSold << " plants for R" << totalRevenue << std::endl;
            std::cout << "New balance: R" << bankAccount->getBalance() << std::endl;
        } else {
            std::cout << "❌ No plants ready to sell!" << std::endl;
        }
    }

    void sellPlantsInSpace(PlantableArea* space, int& plantsSold, double& totalRevenue) {
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                std::vector<Plant*> toRemove;
                
                for (auto plant : plants) {
                    if (plant->getStateName() == "ReadyToSell") {
                        toRemove.push_back(plant);
                        plantsSold++;
                        totalRevenue += 25.0; // Base selling price
                    }
                }
                
                // Remove sold plants
                for (auto plant : toRemove) {
                    box->removePlant(plant);
                    delete plant;
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                sellPlantsInSpace(collection, plantsSold, totalRevenue);
            }
        }
    }

    void gameStatus() {
        std::cout << "\n=== GAME STATUS ===" << std::endl;
        std::cout << "Day: " << dayCounter << std::endl;
        std::cout << "Balance: R" << bankAccount->getBalance() << std::endl;
        std::cout << "Spaces built: " << spaces.size() << std::endl;
        std::cout << "Pending plant commands: " << commandQueue.size() << std::endl;
        std::cout << "Pending transactions: " << transactionManager.commands.size() << std::endl;
        
        int totalPlants = 0;
        for (auto space : spaces) {
            totalPlants += countPlantsInSpace(space);
        }
        std::cout << "Total plants: " << totalPlants << std::endl;
    }

    int countPlantsInSpace(PlantableArea* space) {
        int count = 0;
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                count += box->getPlants().size();
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                count += countPlantsInSpace(collection);
            }
        }
        return count;
    }

    void healthCheck() {
        std::cout << "\n=== HEALTH CHECK (Visitor Pattern) ===" << std::endl;
        
        if (spaces.empty()) {
            std::cout << "No spaces to check!" << std::endl;
            return;
        }
        
        for (size_t i = 0; i < spaces.size(); ++i) {
            std::cout << "\n--- Checking Space " << (i + 1) << " ---" << std::endl;
            performHealthCheckOnSpace(spaces[i]);
        }
    }

    void performHealthCheckOnSpace(PlantableArea* space) {
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    plant->accept(healthVisitor);
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                performHealthCheckOnSpace(collection);
            }
        }
    }

    void viewBankLog() {
        std::cout << "\n=== BANK ACCOUNT LOG (Singleton) ===" << std::endl;
        std::cout << "Current Balance: R" << bankAccount->getBalance() << "\n" << std::endl;
        std::cout << "Transaction History:" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << bankAccount->getLog() << std::endl;
    }

    void viewAllSpaces() {
        std::cout << "\n=== ALL SPACES (Composite Pattern) ===" << std::endl;
        
        if (spaces.empty()) {
            std::cout << "No spaces built yet. Build a space first!" << std::endl;
            return;
        }
        
        std::cout << "Total spaces: " << spaces.size() << "\n" << std::endl;
        
        for (size_t i = 0; i < spaces.size(); ++i) {
            std::cout << "--- Space " << (i + 1) << " ---" << std::endl;
            spaces[i]->display();
            std::cout << std::endl;
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
                case 3: addPlantsWithCommand(); break;
                case 4: careForPlantsWithCommands(); break;
                case 5: removePlantsWithCommand(); break;
                case 6: executeCommandQueue(); break;
                case 7: changeWateringStrategy(); break;
                case 8: advanceDay(); break;
                case 9: sellReadyPlants(); break;
                case 10: gameStatus(); break;
                case 11: healthCheck(); break;
                case 12: viewBankLog(); break;
                case 13: executeFinancialTransactions(); break;
                case 14: 
                    std::cout << "\n=== FINAL STATISTICS ===" << std::endl;
                    std::cout << "Days played: " << dayCounter << std::endl;
                    std::cout << "Final balance: R" << bankAccount->getBalance() << std::endl;
                    std::cout << "Spaces built: " << spaces.size() << std::endl;
                    std::cout << "\nThanks for playing!" << std::endl;
                    break;
                default: 
                    std::cout << "Invalid choice!" << std::endl;
            }
            
        } while (choice != 14);
    }
};

int main() {
    NurseryGame game;
    game.run();
    return 0;
}