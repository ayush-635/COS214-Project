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
#include "src/InteractionManager/InteractionManager.h"
#include "src/Inventory/Inventory.h"
#include "src/InventoryObserver/InventoryObserver.h"
#include "src/Customer/Customer.h"
#include "src/Sales/Sales.h"
#include "src/Cashier/Cashier.h"
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class NurseryGame {
private:
    std::vector<PlantableArea*> spaces;
    std::map<std::string, PlantFactory*> factories;
    std::queue<Duty*> commandQueue;
    BankAccount* bankAccount;
    TransactionManager transactionManager;
    int dayCounter;
    HealthCheckVisitor* healthVisitor;
    WateringStrategy* currentWateringStrategy;
    
    // Staff and customer system
    InteractionManager* mediator;
    Inventory* inventory;
    InventoryObserver* inventoryObserver;
    std::vector<Customer*> customers;
    std::vector<Sales*> salesStaff;
    std::vector<Cashier*> cashiers;
    int customerSpawnCounter;

public:
    NurseryGame() : dayCounter(0), currentWateringStrategy(nullptr), 
                    customerSpawnCounter(0) {
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
        delete healthVisitor;
        
        // Clean up staff and customers
        for (auto customer : customers) {
            delete customer;
        }
        for (auto sales : salesStaff) {
            delete sales;
        }
        for (auto cashier : cashiers) {
            delete cashier;
        }
        
        delete inventoryObserver;
    }

private:
    void initializeGame() {
        std::cout << "\n";
        std::cout << "╔════════════════════════════════════════════════════╗\n";
        std::cout << "║     🌱  WELCOME TO NURSERY MANAGER GAME  🌱      ║\n";
        std::cout << "╚════════════════════════════════════════════════════╝\n";
        std::cout << "\nYou are the owner of a new plant nursery!" << std::endl;
        std::cout << "Your goal: Build spaces, grow plants, and sell them for profit.\n" << std::endl;
        
        std::srand(std::time(nullptr));
        
        // Initialize BankAccount singleton
        bankAccount = BankAccount::getInstance();
        bankAccount->deposit(1000.0, "Starting capital");
        
        // Initialize Inventory singleton
        inventory = Inventory::getInstance();
        
        // Initialize Mediator singleton
        mediator = InteractionManager::getInstance();
        
        // Initialize observer for inventory
        inventoryObserver = new InventoryObserver();
        inventory->attach(inventoryObserver);
        
        // Initialize PlantDataFactory (Flyweight)
        PlantDataFactory::initializeFactory();
        
        // Initialize factories
        factories["flower"] = new FlowerFactory();
        factories["grass"] = new GrassFactory();
        factories["herb"] = new HerbFactory();
        
        // Set factory for inventory
        inventory->setFactory(factories["flower"]);
        
        // Set default watering strategy (Strategy Pattern)
        currentWateringStrategy = new IntermediateWateringStrategy();
        
        // Initialize health visitor
        healthVisitor = new HealthCheckVisitor();
        
        // Create and register plant prototypes
        initializePlantPrototypes();
        
        // Initialize staff
        initializeStaff();
        
        std::cout << "💰 Starting balance: R" << bankAccount->getBalance() << std::endl;
        std::cout << "\n📖 GAME FLOW:" << std::endl;
        std::cout << "1. Build planting spaces" << std::endl;
        std::cout << "2. Buy seeds and plant them" << std::endl;
        std::cout << "3. Care for plants (water & fertilize)" << std::endl;
        std::cout << "4. Advance days to grow plants" << std::endl;
        std::cout << "5. Customers will visit and buy mature plants" << std::endl;
        std::cout << "6. Hire staff to help manage the nursery\n" << std::endl;
        
        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
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
        
        // Add to inventory WITHOUT initial stock (players must buy seeds)
        inventory->addStockType(factories["flower"], "Rose", "Spring");
        inventory->addStockType(factories["flower"], "Tulip", "Spring");
        inventory->addStockType(factories["grass"], "Lawn Grass", "Summer");
        inventory->addStockType(factories["herb"], "Basil", "Summer");
        inventory->addStockType(factories["herb"], "Mint", "Spring");
        
        // Clean up prototypes (factories now own copies)
        delete rosePrototype;
        delete tulipPrototype;
        delete grassPrototype;
        delete basilPrototype;
        delete mintPrototype;
        
        std::cout << "🌼 Available plant types: Rose, Tulip, Lawn Grass, Basil, Mint" << std::endl;
    }

    void initializeStaff() {
        // Create initial sales staff
        Sales* salesPerson = new Sales();
        salesStaff.push_back(salesPerson);
        mediator->addColleague(salesPerson);
        
        // Create initial cashier
        Cashier* cashier = new Cashier();
        cashiers.push_back(cashier);
        mediator->addColleague(cashier);
        
        std::cout << "👥 Hired: 1 Sales staff, 1 Cashier" << std::endl;
    }

    void spawnCustomer() {
        Customer* newCustomer = new Customer();
        customers.push_back(newCustomer);
        mediator->addColleague(newCustomer);
        
        std::cout << "\n👤 A new customer has entered the nursery!" << std::endl;
        
        // Customer sends their preference
        std::string preference = newCustomer->sendPreference();
        std::cout << preference << std::endl;
        
        // Give sales staff time to respond
        std::cout << "💬 Sales staff is helping the customer..." << std::endl;
    }

    void displayMainMenu() {
        std::cout << "\n╔════════════════════════════════════════════════════╗\n";
        std::cout << "║  DAY " << std::left << std::setw(3) << dayCounter 
                  << " | Balance: R" << std::setw(8) << bankAccount->getBalance() 
                  << " | Plants: " << std::setw(3) << countTotalPlants() << "          ║\n";
        std::cout << "╚════════════════════════════════════════════════════╝\n";
        
        std::cout << "\n🏗️  BUILDING & VIEWING" << std::endl;
        std::cout << "  1. Build New Space" << std::endl;
        std::cout << "  2. View All Spaces" << std::endl;
        std::cout << "  3. View Inventory Stock" << std::endl;
        
        std::cout << "\n🌱 PLANT OPERATIONS" << std::endl;
        std::cout << "  4. Buy Seeds (Restock)" << std::endl;
        std::cout << "  5. Plant Seeds in Space" << std::endl;
        std::cout << "  6. Care for Plants (Water/Fertilize)" << std::endl;
        std::cout << "  7. Execute All Queued Commands" << std::endl;
        std::cout << "  8. Change Watering Strategy" << std::endl;
        std::cout << "  9. Health Check (Visitor)" << std::endl;
        
        std::cout << "\n👥 STAFF & CUSTOMERS" << std::endl;
        std::cout << " 10. Hire New Staff" << std::endl;
        std::cout << " 11. Trigger Customer Visit" << std::endl;
        std::cout << " 12. Check Inventory (Cashier)" << std::endl;
        
        std::cout << "\n⏰ TIME & MONEY" << std::endl;
        std::cout << " 13. Advance Day (Grow Plants!)" << std::endl;
        std::cout << " 14. View Bank Log" << std::endl;
        std::cout << " 15. Game Status" << std::endl;
        std::cout << " 16. Exit Game" << std::endl;
        std::cout << "\nChoice: ";
    }

    int countTotalPlants() {
        int total = 0;
        for (auto space : spaces) {
            total += countPlantsInSpace(space);
        }
        return total;
    }

    void buildNewSpace() {
        std::cout << "\n═══ BUILD NEW SPACE ═══" << std::endl;
        std::cout << "1. Small Space (2 boxes) - R50" << std::endl;
        std::cout << "2. Medium Space (4 boxes) - R80" << std::endl;
        std::cout << "3. Big Space (nested, 6 boxes) - R120" << std::endl;
        std::cout << "Choose: ";
        
        int choice;
        std::cin >> choice;
        
        double cost = 0;
        std::string spaceName;
        
        switch (choice) {
            case 1: cost = 50; spaceName = "Small Space"; break;
            case 2: cost = 80; spaceName = "Medium Space"; break;
            case 3: cost = 120; spaceName = "Big Space"; break;
            default:
                std::cout << "❌ Invalid choice!" << std::endl;
                return;
        }
        
        if (bankAccount->getBalance() < cost) {
            std::cout << "❌ Not enough money!" << std::endl;
            std::cout << "   Balance: R" << bankAccount->getBalance() << " | Need: R" << cost << std::endl;
            return;
        }
        
        bankAccount->withdraw(cost, "Built " + spaceName);
        
        NurseryManager manager;
        ConcreteSpaceBuilder* builder = new ConcreteSpaceBuilder();
        manager.setBuilder(builder);
        
        PlantableArea* newSpace = nullptr;
        
        switch (choice) {
            case 1: newSpace = manager.constructSmallSpace(); break;
            case 2: newSpace = manager.constructMediumSpace(); break;
            case 3: newSpace = manager.constructBigSpace(); break;
        }
        
        if (newSpace) {
            spaces.push_back(newSpace);
            std::cout << "✅ " << spaceName << " built successfully!" << std::endl;
            std::cout << "   Total spaces: " << spaces.size() << std::endl;
        }
        
        delete builder;
    }

    void buySeedsRestock() {
        std::cout << "\n═══ BUY SEEDS (Restock Inventory) ═══" << std::endl;
        
        std::vector<std::string> plantNames = inventory->getAllPlantNames();
        std::cout << "Available seeds to buy:\n" << std::endl;
        
        for (size_t i = 0; i < plantNames.size(); ++i) {
            int stock = inventory->getStock(plantNames[i]);
            double cost = getSeedCost(plantNames[i]);
            std::cout << (i + 1) << ". " << std::left << std::setw(15) << plantNames[i] 
                      << "R" << cost << " per seed (Current stock: " << stock << ")" << std::endl;
        }
        
        std::cout << "\nChoose plant (1-" << plantNames.size() << "): ";
        int choice;
        std::cin >> choice;
        
        if (choice < 1 || choice > static_cast<int>(plantNames.size())) {
            std::cout << "❌ Invalid choice!" << std::endl;
            return;
        }
        
        std::string plantName = plantNames[choice - 1];
        
        std::cout << "How many seeds? ";
        int qty;
        std::cin >> qty;
        
        if (qty <= 0) {
            std::cout << "❌ Invalid quantity!" << std::endl;
            return;
        }
        
        double totalCost = getSeedCost(plantName) * qty;
        
        if (bankAccount->getBalance() < totalCost) {
            std::cout << "❌ Not enough money!" << std::endl;
            std::cout << "   Balance: R" << bankAccount->getBalance() << " | Need: R" << totalCost << std::endl;
            return;
        }
        
        bankAccount->withdraw(totalCost, "Bought " + std::to_string(qty) + " " + plantName + " seeds");
        inventory->updateStock(plantName, qty);
        
        std::cout << "✅ Bought " << qty << " " << plantName << " seeds for R" << totalCost << std::endl;
        std::cout << "   New stock: " << inventory->getStock(plantName) << std::endl;
        
        // Notify customers of new stock
        if (qty > 0) {
            mediator->notify(nullptr, "NEW_STOCK:" + plantName);
        }
    }

    double getSeedCost(const std::string& plantName) {
        if (plantName == "Rose") return 8.0;
        else if (plantName == "Tulip") return 6.0;
        else if (plantName == "Lawn Grass") return 4.0;
        else if (plantName == "Basil") return 5.0;
        else if (plantName == "Mint") return 5.0;
        return 5.0;
    }

    void plantSeedsInSpace() {
        if (spaces.empty()) {
            std::cout << "❌ No spaces available! Build a space first (option 1)." << std::endl;
            return;
        }
        
        std::cout << "\n═══ PLANT SEEDS ═══" << std::endl;
        std::cout << "Seeds in inventory:\n" << std::endl;
        
        std::vector<std::string> plantNames = inventory->getAllPlantNames();
        bool hasSeeds = false;
        
        for (size_t i = 0; i < plantNames.size(); ++i) {
            int stock = inventory->getStock(plantNames[i]);
            std::cout << (i + 1) << ". " << std::left << std::setw(15) << plantNames[i] 
                      << "Stock: " << stock << std::endl;
            if (stock > 0) hasSeeds = true;
        }
        
        if (!hasSeeds) {
            std::cout << "\n❌ No seeds in inventory! Buy seeds first (option 4)." << std::endl;
            return;
        }
        
        int plantChoice, spaceChoice, boxIndex;
        std::cout << "\nChoose seed (1-" << plantNames.size() << "): ";
        std::cin >> plantChoice;
        
        if (plantChoice < 1 || plantChoice > static_cast<int>(plantNames.size())) {
            std::cout << "❌ Invalid choice!" << std::endl;
            return;
        }
        
        std::string selectedPlant = plantNames[plantChoice - 1];
        
        if (inventory->getStock(selectedPlant) <= 0) {
            std::cout << "❌ " << selectedPlant << " out of stock! Buy more seeds (option 4)." << std::endl;
            return;
        }
        
        std::cout << "Choose space (1-" << spaces.size() << "): ";
        std::cin >> spaceChoice;
        std::cout << "Choose box index (0-9): ";
        std::cin >> boxIndex;
        
        if (spaceChoice < 1 || spaceChoice > static_cast<int>(spaces.size())) {
            std::cout << "❌ Invalid space!" << std::endl;
            return;
        }
        
        // Create plant from inventory prototype
        Plant* newPlant = nullptr;
        Plant* prototype = inventory->getPrototype(selectedPlant);
        if (prototype) {
            newPlant = prototype->clone();
            newPlant->setID(selectedPlant + "_day" + std::to_string(dayCounter) + "_" + std::to_string(rand() % 1000));
        }
        
        if (newPlant) {
            // Try to sell from inventory (reduces stock)
            if (inventory->trySell(selectedPlant, 1)) {
                // Create and queue plant command
                PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceChoice - 1]);
                if (collection) {
                    PlantSeedCommand* plantCommand = new PlantSeedCommand(collection, newPlant, boxIndex);
                    commandQueue.push(plantCommand);
                    std::cout << "✅ Plant command queued for " << selectedPlant << "!" << std::endl;
                    std::cout << "   Execute commands with option 7" << std::endl;
                    std::cout << "   Commands in queue: " << commandQueue.size() << std::endl;
                } else {
                    std::cout << "❌ Invalid space type!" << std::endl;
                    delete newPlant;
                    inventory->updateStock(selectedPlant, 1); // Return to stock
                }
            } else {
                std::cout << "❌ Failed to take seed from inventory!" << std::endl;
                delete newPlant;
            }
        }
    }

    void careForPlantsWithCommands() {
        if (spaces.empty()) {
            std::cout << "❌ No spaces available!" << std::endl;
            return;
        }
        
        int totalPlants = countTotalPlants();
        if (totalPlants == 0) {
            std::cout << "❌ No plants to care for! Plant some seeds first (option 5)." << std::endl;
            return;
        }
        
        std::cout << "\n═══ CARE FOR PLANTS ═══" << std::endl;
        std::cout << "1. Water Plants - R1 per box" << std::endl;
        std::cout << "2. Fertilize Plants - R3 per box" << std::endl;
        std::cout << "Choose: ";
        
        int choice, spaceChoice, boxIndex;
        std::cin >> choice;
        
        std::cout << "Space (1-" << spaces.size() << "): ";
        std::cin >> spaceChoice;
        std::cout << "Box index (0-9): ";
        std::cin >> boxIndex;
        
        if (spaceChoice < 1 || spaceChoice > static_cast<int>(spaces.size())) {
            std::cout << "❌ Invalid space!" << std::endl;
            return;
        }
        
        double cost = (choice == 1) ? 1 : 3;
        std::string actionName = (choice == 1) ? "Water" : "Fertilizer";
        
        if (bankAccount->getBalance() < cost) {
            std::cout << "❌ Not enough money!" << std::endl;
            std::cout << "   Balance: R" << bankAccount->getBalance() << " | Need: R" << cost << std::endl;
            return;
        }
        
        PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceChoice - 1]);
        if (!collection) {
            std::cout << "❌ Invalid space type!" << std::endl;
            return;
        }
        
        bankAccount->withdraw(cost, "Purchased " + actionName);
        
        if (choice == 1) {
            WaterPlantCommand* waterCommand = new WaterPlantCommand(collection, currentWateringStrategy, boxIndex);
            commandQueue.push(waterCommand);
            std::cout << "✅ Water command queued!" << std::endl;
        } else if (choice == 2) {
            GiveFertilizerCommand* fertilizeCommand = new GiveFertilizerCommand(collection, 1, boxIndex);
            commandQueue.push(fertilizeCommand);
            std::cout << "✅ Fertilize command queued!" << std::endl;
        }
        
        std::cout << "   Execute with option 7 | Queue: " << commandQueue.size() << std::endl;
    }

    void executeCommandQueue() {
        std::cout << "\n═══ EXECUTING COMMANDS ═══" << std::endl;
        
        if (commandQueue.empty()) {
            std::cout << "No commands in queue!" << std::endl;
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
        
        std::cout << "✅ Executed " << commandsExecuted << " commands!" << std::endl;
    }

    void changeWateringStrategy() {
        std::cout << "\n═══ WATERING STRATEGY ═══" << std::endl;
        std::cout << "1. Light (1 unit)" << std::endl;
        std::cout << "2. Intermediate (3 units)" << std::endl;
        std::cout << "3. Heavy (5 units)" << std::endl;
        std::cout << "Choose: ";
        
        int choice;
        std::cin >> choice;
        
        delete currentWateringStrategy;
        
        switch (choice) {
            case 1:
                currentWateringStrategy = new LightWateringStrategy();
                std::cout << "✅ Light Watering" << std::endl;
                break;
            case 2:
                currentWateringStrategy = new IntermediateWateringStrategy();
                std::cout << "✅ Intermediate Watering" << std::endl;
                break;
            case 3:
                currentWateringStrategy = new HeavyWateringStrategy();
                std::cout << "✅ Heavy Watering" << std::endl;
                break;
            default:
                currentWateringStrategy = new IntermediateWateringStrategy();
                std::cout << "❌ Invalid, using Intermediate" << std::endl;
                break;
        }
    }

    void advanceDay() {
        std::cout << "\n═══ ADVANCING TO DAY " << (dayCounter + 1) << " ═══" << std::endl;
        dayCounter++;
        
        // Update all plants in all spaces
        int plantsUpdated = 0;
        for (auto space : spaces) {
            plantsUpdated += updatePlantsInSpace(space);
        }
        
        std::cout << "✅ Updated " << plantsUpdated << " plants!" << std::endl;
        showStateChanges();
        
        // Check for mature plants ready to sell
        int readyPlants = countReadyPlants();
        if (readyPlants > 0) {
            std::cout << "\n💰 " << readyPlants << " plant(s) ready to sell! Customers may visit." << std::endl;
        }
        
        // Random customer spawn (50% if plants ready)
        customerSpawnCounter++;
        if (readyPlants > 0 && (customerSpawnCounter >= 2 || (rand() % 100) < 50)) {
            spawnCustomer();
            customerSpawnCounter = 0;
            
            // Customer attempts purchase
            if (!customers.empty()) {
                Customer* customer = customers.back();
                customer->purchaseRandomPlants();
            }
        }
    }

    int updatePlantsInSpace(PlantableArea* space) {
        int count = 0;
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
                        std::cout << "  🔄 " << plant->getName() << ": " << oldState << " → " << newState << std::endl;
                    }
                    count++;
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                count += updatePlantsInSpace(collection);
            }
        }
        return count;
    }

    int countReadyPlants() {
        int ready = 0;
        for (auto space : spaces) {
            ready += countReadyInSpace(space);
        }
        return ready;
    }

    int countReadyInSpace(PlantableArea* space) {
        int count = 0;
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                for (auto plant : box->getPlants()) {
                    if (plant->getStateName() == "ReadyToSell") count++;
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                count += countReadyInSpace(collection);
            }
        }
        return count;
    }

    void showStateChanges() {
        int seedlings = 0, growing = 0, mature = 0, ready = 0, dying = 0, dead = 0;
        
        for (auto space : spaces) {
            countPlantStates(space, seedlings, growing, mature, ready, dying, dead);
        }
        
        std::cout << "\n📊 Plant States:" << std::endl;
        std::cout << "   🌱 Seedlings: " << seedlings << " | 🌿 Growing: " << growing << " | 🌳 Mature: " << mature << std::endl;
        std::cout << "   💰 Ready: " << ready << " | ⚠️  Dying: " << dying << " | 💀 Dead: " << dead << std::endl;
    }

    void countPlantStates(PlantableArea* space, int& seedlings, int& growing, int& mature, 
                         int& ready, int& dying, int& dead) {
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                for (auto plant : box->getPlants()) {
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

    void hireStaff() {
        std::cout << "\n═══ HIRE STAFF ═══" << std::endl;
        std::cout << "1. Sales Staff - R100" << std::endl;
        std::cout << "2. Cashier - R80" << std::endl;
        std::cout << "Choose: ";
        
        int choice;
        std::cin >> choice;
        
        double cost = (choice == 1) ? 100 : 80;
        std::string staffType = (choice == 1) ? "Sales Staff" : "Cashier";
        
        if (bankAccount->getBalance() < cost) {
            std::cout << "❌ Not enough money!" << std::endl;
            std::cout << "   Balance: R" << bankAccount->getBalance() << " | Need: R" << cost << std::endl;
            return;
        }
        
        bankAccount->withdraw(cost, "Hired " + staffType);
        
        if (choice == 1) {
            Sales* newSales = new Sales();
            salesStaff.push_back(newSales);
            mediator->addColleague(newSales);
            std::cout << "✅ Hired Sales staff!" << std::endl;
        } else if (choice == 2) {
            Cashier* newCashier = new Cashier();
            cashiers.push_back(newCashier);
            mediator->addColleague(newCashier);
            std::cout << "✅ Hired Cashier!" << std::endl;
        }
        
        std::cout << "   Total staff: " << (salesStaff.size() + cashiers.size()) << std::endl;
    }

    void customerVisit() {
        std::cout << "\n═══ CUSTOMER VISIT ═══" << std::endl;
        
        if (salesStaff.empty()) {
            std::cout << "❌ No sales staff! Hire staff first (option 10)." << std::endl;
            return;
        }
        
        int readyPlants = countReadyPlants();
        if (readyPlants == 0) {
            std::cout << "⚠️  No plants ready to sell! Customers won't buy anything." << std::endl;
        }
        
        spawnCustomer();
        
        // Customer attempts purchase
        if (!customers.empty()) {
            Customer* customer = customers.back();
            std::cout << "\n💰 Customer attempting purchase..." << std::endl;
            customer->purchaseRandomPlants();
            
            std::string advice = customer->receiveAdvice();
            if (!advice.empty()) {
                std::cout << "   " << advice << std::endl;
            }
        }
    }

    void checkInventoryWithCashier() {
        std::cout << "\n═══ CHECK INVENTORY (Cashier) ═══" << std::endl;
        
        if (cashiers.empty()) {
            std::cout << "❌ No cashiers! Hire one first (option 10)." << std::endl;
            return;
        }
        
        std::vector<std::string> plantNames = inventory->getAllPlantNames();
        std::cout << "Available plants:\n" << std::endl;
        for (size_t i = 0; i < plantNames.size(); ++i) {
            std::cout << (i + 1) << ". " << plantNames[i] << std::endl;
        }
        
        std::cout << "\nChoose plant (1-" << plantNames.size() << "): ";
        int choice;
        std::cin >> choice;
        
        if (choice < 1 || choice > static_cast<int>(plantNames.size())) {
            std::cout << "❌ Invalid choice!" << std::endl;
            return;
        }
        
        std::string plantName = plantNames[choice - 1];
        
        Cashier* cashier = cashiers[0];
        std::string checkMsg = "CHECK:" + plantName;
        cashier->receivePreference(checkMsg);
    }

    void viewInventory() {
        std::cout << "\n═══ INVENTORY STOCK ═══" << std::endl;
        
        std::vector<std::string> plantNames = inventory->getAllPlantNames();
        if (plantNames.empty()) {
            std::cout << "No plants in inventory!" << std::endl;
            return;
        }
        
        std::cout << "\n" << std::left << std::setw(18) << "Plant Type" 
                  << std::setw(10) << "Stock" << "Ideal Season" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        
        int totalStock = 0;
        for (const std::string& name : plantNames) {
            int stock = inventory->getStock(name);
            std::string season = inventory->getIdealSeason(name);
            totalStock += stock;
            
            std::cout << std::left << std::setw(18) << name 
                      << std::setw(10) << stock << season << std::endl;
        }
        
        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "Total seeds: " << totalStock << std::endl;
    }

    void gameStatus() {
        std::cout << "\n═══════════════════════════════════════════════" << std::endl;
        std::cout << "              GAME STATUS - DAY " << dayCounter << std::endl;
        std::cout << "═══════════════════════════════════════════════" << std::endl;
        
        std::cout << "\n💰 FINANCES" << std::endl;
        std::cout << "   Balance: R" << bankAccount->getBalance() << std::endl;
        std::cout << "   Pending commands: " << commandQueue.size() << std::endl;
        
        std::cout << "\n🏗️  INFRASTRUCTURE" << std::endl;
        std::cout << "   Spaces built: " << spaces.size() << std::endl;
        
        std::cout << "\n👥 STAFF" << std::endl;
        std::cout << "   Sales Staff: " << salesStaff.size() << std::endl;
        std::cout << "   Cashiers: " << cashiers.size() << std::endl;
        std::cout << "   Customers today: " << customers.size() << std::endl;
        
        std::cout << "\n🌱 PLANTS" << std::endl;
        int totalPlants = countTotalPlants();
        std::cout << "   Growing: " << totalPlants << std::endl;
        
        int seedlings = 0, growing = 0, mature = 0, ready = 0, dying = 0, dead = 0;
        for (auto space : spaces) {
            countPlantStates(space, seedlings, growing, mature, ready, dying, dead);
        }
        
        std::cout << "   └─ Seedlings: " << seedlings << " | Growing: " << growing << std::endl;
        std::cout << "   └─ Mature: " << mature << " | Ready to Sell: " << ready << std::endl;
        std::cout << "   └─ Dying: " << dying << " | Dead: " << dead << std::endl;
        
        std::cout << "\n📦 INVENTORY" << std::endl;
        std::vector<std::string> plantNames = inventory->getAllPlantNames();
        int totalStock = 0;
        for (const std::string& name : plantNames) {
            int stock = inventory->getStock(name);
            totalStock += stock;
            if (stock > 0) {
                std::cout << "   " << name << ": " << stock << " seeds" << std::endl;
            }
        }
        std::cout << "   Total seeds: " << totalStock << std::endl;
        
        std::cout << "═══════════════════════════════════════════════\n" << std::endl;
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
        std::cout << "\n═══ HEALTH CHECK (Visitor) ═══" << std::endl;
        
        if (spaces.empty()) {
            std::cout << "No spaces to check!" << std::endl;
            return;
        }
        
        int totalPlantsChecked = 0;
        
        for (size_t i = 0; i < spaces.size(); ++i) {
            std::cout << "\n--- Space " << (i + 1) << " ---" << std::endl;
            totalPlantsChecked += performHealthCheckOnSpace(spaces[i]);
        }
        
        std::cout << "\n✅ Checked " << totalPlantsChecked << " plants!" << std::endl;
    }

    int performHealthCheckOnSpace(PlantableArea* space) {
        int count = 0;
        for (int i = 0; i < 10; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    if (plant) {
                        plant->accept(*healthVisitor);
                        count++;
                    }
                }
            }
            
            PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(child);
            if (collection) {
                count += performHealthCheckOnSpace(collection);
            }
        }
        return count;
    }

    void viewBankLog() {
        std::cout << "\n═══ BANK ACCOUNT LOG ═══" << std::endl;
        std::cout << "Current Balance: R" << bankAccount->getBalance() << "\n" << std::endl;
        std::cout << "Transaction History:" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << bankAccount->getLog() << std::endl;
    }

    void viewAllSpaces() {
        std::cout << "\n═══ ALL SPACES ═══" << std::endl;
        
        if (spaces.empty()) {
            std::cout << "No spaces built! Build one first (option 1)." << std::endl;
            return;
        }
        
        std::cout << "Total spaces: " << spaces.size() << "\n" << std::endl;
        
        for (size_t i = 0; i < spaces.size(); ++i) {
            std::cout << "╔═══ Space " << (i + 1) << " ═══╗" << std::endl;
            spaces[i]->display();
            
            // Count plants in this space
            int plantCount = countPlantsInSpace(spaces[i]);
            std::cout << "└─ Plants in space: " << plantCount << std::endl;
            std::cout << std::endl;
        }
    }

public:
    void run() {
        int choice;
        
        do {
            displayMainMenu();
            std::cin >> choice;
            
            // Clear input buffer
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "❌ Invalid input!" << std::endl;
                continue;
            }
            
            switch (choice) {
                case 1: buildNewSpace(); break;
                case 2: viewAllSpaces(); break;
                case 3: viewInventory(); break;
                case 4: buySeedsRestock(); break;
                case 5: plantSeedsInSpace(); break;
                case 6: careForPlantsWithCommands(); break;
                case 7: executeCommandQueue(); break;
                case 8: changeWateringStrategy(); break;
                case 9: healthCheck(); break;
                case 10: hireStaff(); break;
                case 11: customerVisit(); break;
                case 12: checkInventoryWithCashier(); break;
                case 13: advanceDay(); break;
                case 14: viewBankLog(); break;
                case 15: gameStatus(); break;
                case 16: {
                    std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
                    std::cout << "║           FINAL STATISTICS                     ║" << std::endl;
                    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
                    std::cout << "\n📅 Days played: " << dayCounter << std::endl;
                    std::cout << "💰 Final balance: R" << bankAccount->getBalance() << std::endl;
                    std::cout << "🏗️  Spaces built: " << spaces.size() << std::endl;
                    std::cout << "👥 Staff hired: " << (salesStaff.size() + cashiers.size()) << std::endl;
                    std::cout << "🛒 Customers served: " << customers.size() << std::endl;
                    std::cout << "🌱 Total plants grown: " << countTotalPlants() << std::endl;
                    
                    double profit = bankAccount->getBalance() - 1000.0;
                    std::cout << "\n💵 Profit/Loss: R" << profit << std::endl;
                    
                    if (profit > 500) {
                        std::cout << "\n🏆 Excellent work! Your nursery is thriving!" << std::endl;
                    } else if (profit > 0) {
                        std::cout << "\n👍 Good job! You made a profit!" << std::endl;
                    } else {
                        std::cout << "\n💪 Keep trying! Better luck next time!" << std::endl;
                    }
                    
                    std::cout << "\n🌱 Thanks for playing Nursery Manager! 🌱\n" << std::endl;
                    break;}
                default: 
                    std::cout << "❌ Invalid choice! Choose 1-16." << std::endl;
            }
            
        } while (choice != 16);
    }
};

int main() {
    NurseryGame game;
    game.run();
    return 0;
}