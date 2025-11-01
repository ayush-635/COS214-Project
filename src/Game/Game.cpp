// src/Game/Game.cpp - FACADE PATTERN IMPLEMENTATION
#include "Game.h"
#include "../ConcreteSpaceBuilder/ConcreteSpaceBuilder.h"
#include "../PlanterBox/PlanterBox.h"
#include "../PlanterBoxCollection/PlanterBoxCollection.h"
#include "../PlantDataFactory/PlantDataFactory.h"
#include "../FlowerFactory/FlowerFactory.h"
#include "../GrassFactory/GrassFactory.h"
#include "../HerbFactory/HerbFactory.h"
#include "../FlowerPlant/FlowerPlant.h"
#include "../GrassPlant/GrassPlant.h"
#include "../HerbPlant/HerbPlant.h"
#include "../PlantSeedCommand/PlantSeedCommand.h"
#include "../WaterPlantCommand/WaterPlantCommand.h"
#include "../GiveFertilizerCommand/GiveFertilizerCommand.h"
#include "../LightWateringStrategy/LightWateringStrategy.h"
#include "../IntermediateWateringStrategy/IntermediateWateringStrategy.h"
#include "../HeavyWateringStrategy/HeavyWateringStrategy.h"
#include "../TransactionManager/TransactionManager.h"
#include "../InventoryObserver/InventoryObserver.h"
#include "../Customer/Customer.h"
#include "../Sales/Sales.h"
#include "../Cashier/Cashier.h"
#include "../OrderItem/OrderItem.h"
#include "../DeliveryStrategy/DeliveryStrategy.h"
#include "../StandardDelivery/StandardDelivery.h"
#include "../ExpressDelivery/ExpressDelivery.h"
#include "../PickupDelivery/PickupDelivery.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Game* Game::instance = nullptr;

Game::Game() : dayCounter(0), customerSpawnCounter(0), happinessScore(100) {
    std::srand(std::time(nullptr));
    transactionManager = new TransactionManager();
}

Game::~Game() {
    for (auto space : spaces) delete space;
    for (auto& factory : factories) delete factory.second;
    while (!commandQueue.empty()) {
        delete commandQueue.front();
        commandQueue.pop();
    }
    delete currentWateringStrategy;
    delete healthVisitor;
    for (auto customer : customers) delete customer;
    for (auto sales : salesStaff) delete sales;
    for (auto cashier : cashiers) delete cashier;
    for (auto order : orders) delete order;
    delete inventoryObserver;
    delete transactionManager;
}

Game* Game::getInstance() {
    if (!instance) {
        instance = new Game();
    }
    return instance;
}

void Game::initialize() {
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║     🌱  WELCOME TO NURSERY MANAGER GAME  🌱      ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
    std::cout << "\nYou own a new plant nursery!" << std::endl;
    std::cout << "Goal: Build, grow, and sell plants for profit.\n" << std::endl;
    
    // Initialize all subsystems
    bankAccount = BankAccount::getInstance();
    bankAccount->deposit(1000.0, "Starting capital");
    
    inventory = Inventory::getInstance();
    mediator = InteractionManager::getInstance();
    
    inventoryObserver = new InventoryObserver();
    inventory->attach(inventoryObserver);
    
    PlantDataFactory::initializeFactory();
    
    factories["flower"] = new FlowerFactory();
    factories["grass"] = new GrassFactory();
    factories["herb"] = new HerbFactory();
    
    inventory->setFactory(factories["flower"]);
    currentWateringStrategy = new IntermediateWateringStrategy();
    healthVisitor = new HealthCheckVisitor();
    
    initializePlantPrototypes();
    initializeStaff();
    
    std::cout << "💰 Starting: R" << bankAccount->getBalance() << std::endl;
    std::cout << "😊 Happiness: " << happinessScore << "/100\n" << std::endl;
    
    std::cout << "📖 Quick Start:" << std::endl;
    std::cout << "1. Build spaces → 2. Buy seeds → 3. Plant → 4. Execute commands" << std::endl;
    std::cout << "5. Care (water/fertilize) → 6. Advance days → 7. Sell to customers\n" << std::endl;
}

void Game::initializePlantPrototypes() {
    auto flowerData = PlantDataFactory::getPlantData("FlowerPlant");
    auto grassData = PlantDataFactory::getPlantData("GrassPlant");
    auto herbData = PlantDataFactory::getPlantData("HerbPlant");
    
    FlowerPlant* roseProto = new FlowerPlant("proto_rose", "Rose", flowerData);
    FlowerPlant* tulipProto = new FlowerPlant("proto_tulip", "Tulip", flowerData);
    GrassPlant* grassProto = new GrassPlant("proto_grass", "Lawn Grass", grassData);
    HerbPlant* basilProto = new HerbPlant("proto_basil", "Basil", herbData);
    HerbPlant* mintProto = new HerbPlant("proto_mint", "Mint", herbData);
    
    factories["flower"]->addPlantPrototype(roseProto);
    factories["flower"]->addPlantPrototype(tulipProto);
    factories["grass"]->addPlantPrototype(grassProto);
    factories["herb"]->addPlantPrototype(basilProto);
    factories["herb"]->addPlantPrototype(mintProto);
    
    inventory->addStockType(factories["flower"], "Rose", "Spring");
    inventory->addStockType(factories["flower"], "Tulip", "Spring");
    inventory->addStockType(factories["grass"], "Lawn Grass", "Summer");
    inventory->addStockType(factories["herb"], "Basil", "Summer");
    inventory->addStockType(factories["herb"], "Mint", "Spring");
    
    delete roseProto;
    delete tulipProto;
    delete grassProto;
    delete basilProto;
    delete mintProto;
}

void Game::initializeStaff() {
    Sales* sales = new Sales();
    salesStaff.push_back(sales);
    mediator->addColleague(sales);
    
    Cashier* cashier = new Cashier();
    cashiers.push_back(cashier);
    mediator->addColleague(cashier);
}

bool Game::buildSpace(int spaceType) {
    double cost = 0;
    std::string name;
    
    switch (spaceType) {
        case 1: cost = 50; name = "Small"; break;
        case 2: cost = 80; name = "Medium"; break;
        case 3: cost = 120; name = "Big"; break;
        default: return false;
    }
    
    if (bankAccount->getBalance() < cost) return false;
    
    bankAccount->withdraw(cost, "Built " + name + " space");
    
    NurseryManager manager;
    ConcreteSpaceBuilder* builder = new ConcreteSpaceBuilder();
    manager.setBuilder(builder);
    
    PlantableArea* newSpace = nullptr;
    switch (spaceType) {
        case 1: newSpace = manager.constructSmallSpace(); break;
        case 2: newSpace = manager.constructMediumSpace(); break;
        case 3: newSpace = manager.constructBigSpace(); break;
    }
    
    if (newSpace) {
        spaces.push_back(newSpace);
    }
    
    delete builder;
    return newSpace != nullptr;
}

bool Game::buySeed(const std::string& plantName, int quantity) {
    if (quantity <= 0) return false;
    
    double cost = getSeedCost(plantName) * quantity;
    if (bankAccount->getBalance() < cost) return false;
    
    bankAccount->withdraw(cost, "Bought " + std::to_string(quantity) + " " + plantName);
    inventory->updateStock(plantName, quantity);
    
    if (quantity > 0) {
        mediator->notify(nullptr, "NEW_STOCK:" + plantName);
    }
    
    return true;
}

bool Game::plantSeed(const std::string& plantName, int spaceIndex, int boxIndex) {
    if (spaceIndex < 0 || spaceIndex >= (int)spaces.size()) return false;
    if (inventory->getStock(plantName) <= 0) return false;
    
    Plant* prototype = inventory->getPrototype(plantName);
    if (!prototype) return false;
    
    Plant* newPlant = prototype->clone();
    newPlant->setID(plantName + "_d" + std::to_string(dayCounter) + "_" + std::to_string(rand() % 1000));
    
    if (inventory->trySell(plantName, 1)) {
        PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceIndex]);
        if (collection) {
            PlantSeedCommand* cmd = new PlantSeedCommand(collection, newPlant, boxIndex);
            commandQueue.push(cmd);
            return true;
        } else {
            delete newPlant;
            inventory->updateStock(plantName, 1);
        }
    } else {
        delete newPlant;
    }
    return false;
}

bool Game::waterPlants(int spaceIndex, int boxIndex) {
    if (spaceIndex < 0 || spaceIndex >= (int)spaces.size()) return false;
    if (bankAccount->getBalance() < 1) return false;
    
    PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceIndex]);
    if (!collection) return false;
    
    bankAccount->withdraw(1, "Water");
    WaterPlantCommand* cmd = new WaterPlantCommand(collection, currentWateringStrategy, boxIndex);
    commandQueue.push(cmd);
    return true;
}

bool Game::fertilizePlants(int spaceIndex, int boxIndex) {
    if (spaceIndex < 0 || spaceIndex >= (int)spaces.size()) return false;
    if (bankAccount->getBalance() < 3) return false;
    
    PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(spaces[spaceIndex]);
    if (!collection) return false;
    
    bankAccount->withdraw(3, "Fertilizer");
    GiveFertilizerCommand* cmd = new GiveFertilizerCommand(collection, 1, boxIndex);
    commandQueue.push(cmd);
    return true;
}

void Game::executeCommands() {
    int count = 0;
    while (!commandQueue.empty()) {
        Duty* cmd = commandQueue.front();
        cmd->executeDuty();
        delete cmd;
        commandQueue.pop();
        count++;
    }
    std::cout << "✅ Executed " << count << " commands!" << std::endl;
}

void Game::changeWateringStrategy(int type) {
    delete currentWateringStrategy;
    switch (type) {
        case 1: currentWateringStrategy = new LightWateringStrategy(); break;
        case 2: currentWateringStrategy = new IntermediateWateringStrategy(); break;
        case 3: currentWateringStrategy = new HeavyWateringStrategy(); break;
        default: currentWateringStrategy = new IntermediateWateringStrategy(); break;
    }
}

void Game::advanceDay() {
    dayCounter++;
    std::cout << "\n═══ DAY " << dayCounter << " ═══" << std::endl;
    
    int updated = 0;
    for (auto space : spaces) {
        updatePlantsInSpace(space, updated);
    }
    
    std::cout << "✅ " << updated << " plants updated!" << std::endl;
    
    int ready = getReadyPlantsCount();
    if (ready > 0) {
        std::cout << "💰 " << ready << " plants ready!" << std::endl;
        
        customerSpawnCounter++;
        if (customerSpawnCounter >= 2 || (rand() % 100) < 50) {
            triggerCustomerVisit();
            customerSpawnCounter = 0;
        }
    }
}

void Game::updatePlantsInSpace(PlantableArea* space, int& updated) {
    for (int i = 0; i < 10; ++i) {
        PlantableArea* child = space->getChild(i);
        if (!child) break;
        
        PlanterBox* box = dynamic_cast<PlanterBox*>(child);
        if (box) {
            for (auto plant : box->getPlants()) {
                std::string oldState = plant->getStateName();
                plant->update();
                std::string newState = plant->getStateName();
                
                if (oldState != newState) {
                    std::cout << "  🔄 " << plant->getName() << ": " << oldState << " → " << newState << std::endl;
                }
                updated++;
            }
        }
        
        PlanterBoxCollection* coll = dynamic_cast<PlanterBoxCollection*>(child);
        if (coll) updatePlantsInSpace(coll, updated);
    }
}

bool Game::hireStaff(int type) {
    double cost = (type == 1) ? 100 : 80;
    if (bankAccount->getBalance() < cost) return false;
    
    bankAccount->withdraw(cost, type == 1 ? "Hired Sales" : "Hired Cashier");
    
    if (type == 1) {
        Sales* s = new Sales();
        salesStaff.push_back(s);
        mediator->addColleague(s);
    } else {
        Cashier* c = new Cashier();
        cashiers.push_back(c);
        mediator->addColleague(c);
    }
    return true;
}

void Game::spawnCustomer() {
    Customer* c = new Customer();
    customers.push_back(c);
    mediator->addColleague(c);
    
    std::cout << "\n👤 Customer entered!" << std::endl;
    std::string pref = c->sendPreference();
    std::cout << pref << std::endl;
}

void Game::triggerCustomerVisit() {
    if (salesStaff.empty()) {
        std::cout << "⚠️  No sales staff!" << std::endl;
        return;
    }
    
    spawnCustomer();
    
    if (!customers.empty()) {
        Customer* customer = customers.back();
        customer->purchaseRandomPlants();
        
        // Create order from ready plants
        Order* order = createOrderFromReadyPlants();
        
        if (order && order->total() > 0) {
            orders.push_back(order);
            
            // Add pots randomly (50% chance per item)
            std::cout << "  🏺 Adding decorative pots..." << std::endl;
            
            // Process with random delivery strategy
            int deliveryType = (rand() % 3) + 1;
            processOrderWithDelivery(order, deliveryType);
            
            // Revenue from sale
            double revenue = order->total();
            bankAccount->deposit(revenue, "Plant sales");
            updateHappiness(true);
            
            std::cout << "✅ Sale: R" << revenue << std::endl;
        } else {
            updateHappiness(false);
            std::cout << "😞 No plants available!" << std::endl;
            if (order) delete order;
        }
    }
}

Order* Game::createOrderFromReadyPlants() {
    Order* order = new Order();
    int plantsAdded = 0;
    int maxPlants = 1 + (rand() % 3); // 1-3 plants
    
    for (auto space : spaces) {
        if (plantsAdded >= maxPlants) break;
        
        for (int i = 0; i < 10 && plantsAdded < maxPlants; ++i) {
            PlantableArea* child = space->getChild(i);
            if (!child) break;
            
            PlanterBox* box = dynamic_cast<PlanterBox*>(child);
            if (box) {
                auto plants = box->getPlants();
                for (auto plant : plants) {
                    if (plant->getStateName() == "ReadyToSell" && plantsAdded < maxPlants) {
                        double price = 25.0 + (rand() % 26); // R25-R50
                        OrderItem* item = new OrderItem(plant->getName(), price, 1);
                        
                        // Add pot with 50% chance (Decorator pattern)
                        if (rand() % 100 < 50) {
                            item->addPot();
                        }
                        
                        order->addItem(item);
                        
                        // Remove sold plant
                        box->removePlant(plant);
                        delete plant;
                        plantsAdded++;
                        break;
                    }
                }
            }
        }
    }
    
    return order;
}

void Game::processOrderWithDelivery(Order* order, int deliveryType) {
    DeliveryStrategy* delivery = nullptr;
    
    switch (deliveryType) {
        case 1: delivery = new StandardDelivery(); break;
        case 2: delivery = new ExpressDelivery(); break;
        case 3: delivery = new PickupDelivery(); break;
        default: delivery = new StandardDelivery(); break;
    }
    
    if (delivery) {
        std::cout << "\n";
        delivery->deliver(*order);
        delete delivery;
    }
}

void Game::updateHappiness(bool satisfied) {
    if (satisfied) {
        happinessScore = std::min(100, happinessScore + 5);
        std::cout << "😊 +5 happiness (Now: " << happinessScore << ")" << std::endl;
    } else {
        happinessScore = std::max(0, happinessScore - 10);
        std::cout << "😞 -10 happiness (Now: " << happinessScore << ")" << std::endl;
    }
}

void Game::performHealthCheck() {
    int total = 0;
    for (auto space : spaces) {
        total += performHealthCheckOnSpace(space);
    }
    std::cout << "✅ Checked " << total << " plants" << std::endl;
}

int Game::performHealthCheckOnSpace(PlantableArea* space) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        PlantableArea* child = space->getChild(i);
        if (!child) break;
        
        PlanterBox* box = dynamic_cast<PlanterBox*>(child);
        if (box) {
            for (auto plant : box->getPlants()) {
                if (plant) {
                    plant->accept(*healthVisitor);
                    count++;
                }
            }
        }
        
        PlanterBoxCollection* coll = dynamic_cast<PlanterBoxCollection*>(child);
        if (coll) count += performHealthCheckOnSpace(coll);
    }
    return count;
}

void Game::viewInventoryStock() {
    auto names = inventory->getAllPlantNames();
    std::cout << "\n═══ INVENTORY ═══" << std::endl;
    for (const auto& name : names) {
        std::cout << "  " << name << ": " << inventory->getStock(name) << std::endl;
    }
}

void Game::viewAllSpaces() {
    std::cout << "\n═══ SPACES (" << spaces.size() << ") ═══" << std::endl;
    for (size_t i = 0; i < spaces.size(); ++i) {
        std::cout << "Space " << (i+1) << ": " << countPlantsInSpace(spaces[i]) << " plants" << std::endl;
    }
}

void Game::viewBankLog() {
    std::cout << "\n═══ BANK LOG ===\n" << bankAccount->getLog() << std::endl;
}

void Game::displayGameStatus() {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║        GAME STATUS - DAY " << std::left << std::setw(3) << dayCounter << "       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::cout << "💰 Balance: R" << bankAccount->getBalance() << std::endl;
    std::cout << "😊 Happiness: " << happinessScore << "/100" << std::endl;
    std::cout << "🏗️  Spaces: " << spaces.size() << std::endl;
    std::cout << "🌱 Plants: " << getTotalPlants() << std::endl;
    std::cout << "💰 Ready: " << getReadyPlantsCount() << std::endl;
    std::cout << "👥 Staff: " << (salesStaff.size() + cashiers.size()) << std::endl;
    std::cout << "🛒 Orders: " << orders.size() << std::endl;
}

double Game::getBalance() const {
    return bankAccount->getBalance();
}

int Game::getTotalPlants() {
    int total = 0;
    for (auto space : spaces) {
        total += countPlantsInSpace(space);
    }
    return total;
}

int Game::countPlantsInSpace(PlantableArea* space) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        PlantableArea* child = space->getChild(i);
        if (!child) break;
        
        PlanterBox* box = dynamic_cast<PlanterBox*>(child);
        if (box) count += box->getPlants().size();
        
        PlanterBoxCollection* coll = dynamic_cast<PlanterBoxCollection*>(child);
        if (coll) count += countPlantsInSpace(coll);
    }
    return count;
}

int Game::getReadyPlantsCount() {
    int ready = 0;
    for (auto space : spaces) {
        ready += countReadyInSpace(space);
    }
    return ready;
}

int Game::countReadyInSpace(PlantableArea* space) {
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
        
        PlanterBoxCollection* coll = dynamic_cast<PlanterBoxCollection*>(child);
        if (coll) count += countReadyInSpace(coll);
    }
    return count;
}

double Game::getSeedCost(const std::string& name) {
    if (name == "Rose") return 8.0;
    if (name == "Tulip") return 6.0;
    if (name == "Lawn Grass") return 4.0;
    if (name == "Basil") return 5.0;
    if (name == "Mint") return 5.0;
    return 5.0;
}

int Game::getInventoryStock(const std::string& name) {
    return inventory->getStock(name);
}

void Game::countPlantStates(PlantableArea* space, int& seedlings, int& growing, 
                           int& mature, int& ready, int& dying, int& dead) {
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
        
        PlanterBoxCollection* coll = dynamic_cast<PlanterBoxCollection*>(child);
        if (coll) countPlantStates(coll, seedlings, growing, mature, ready, dying, dead);
    }
}