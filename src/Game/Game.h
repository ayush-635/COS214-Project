// src/Game/Game.h - FACADE PATTERN
#ifndef GAME_H
#define GAME_H

#include "../Plant/Plant.h"
#include "../HealthCheckVisitor/HealthCheckVisitor.h"
#include "../NurseryManager/NurseryManager.h"
#include "../BankAccount/BankAccount.h"
#include "../Inventory/Inventory.h"
#include "../InteractionManager/InteractionManager.h"
#include "../Order/Order.h"
#include "../PlantableArea/PlantableArea.h"
#include "../PlantFactory/PlantFactory.h"
#include "../WateringStrategy/WateringStrategy.h"
#include "../Duty/Duty.h"
#include <vector>
#include <memory>
#include <map>
#include <queue>
#include <string>

class InventoryObserver;
class Customer;
class Sales;
class Cashier;
class TransactionManager;

// FACADE PATTERN - Simplifies all subsystems
class Game {
private:
    static Game* instance;
    
    // All subsystems (hidden from user)
    std::vector<PlantableArea*> spaces;
    std::map<std::string, PlantFactory*> factories;
    std::queue<Duty*> commandQueue;
    BankAccount* bankAccount;
    TransactionManager* transactionManager;
    HealthCheckVisitor* healthVisitor;
    WateringStrategy* currentWateringStrategy;
    InteractionManager* mediator;
    Inventory* inventory;
    InventoryObserver* inventoryObserver;
    
    std::vector<Customer*> customers;
    std::vector<Sales*> salesStaff;
    std::vector<Cashier*> cashiers;
    std::vector<Order*> orders;
    
    int dayCounter;
    int customerSpawnCounter;
    int happinessScore;
    
    Game();
    ~Game();
    
    // Helper methods
    void initializePlantPrototypes();
    void initializeStaff();
    void spawnCustomer();
    int countPlantsInSpace(PlantableArea* space);
    int countReadyInSpace(PlantableArea* space);
    void updatePlantsInSpace(PlantableArea* space, int& plantsUpdated);
    void countPlantStates(PlantableArea* space, int& seedlings, int& growing, 
                         int& mature, int& ready, int& dying, int& dead);
    int performHealthCheckOnSpace(PlantableArea* space);
    double getSeedCost(const std::string& plantName);
    void updateHappiness(bool customerSatisfied);
    Order* createOrderFromReadyPlants();

public:
    // Singleton
    static Game* getInstance();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    
    // Simplified interface (Facade methods)
    void initialize();
    
    // Building operations
    bool buildSpace(int spaceType);
    void viewAllSpaces();
    
    // Inventory operations
    bool buySeed(const std::string& plantName, int quantity);
    void viewInventoryStock();
    int getInventoryStock(const std::string& plantName);
    
    // Planting operations
    bool plantSeed(const std::string& plantName, int spaceIndex, int boxIndex);
    bool waterPlants(int spaceIndex, int boxIndex);
    bool fertilizePlants(int spaceIndex, int boxIndex);
    void executeCommands();
    void changeWateringStrategy(int strategyType);
    
    // Time progression
    void advanceDay();
    void performHealthCheck();
    
    // Staff management
    bool hireStaff(int staffType);
    void triggerCustomerVisit();
    
    // Iterator demonstration
    void useIterator();
    
    // Status & Information
    void displayGameStatus();
    void viewBankLog();
    void viewOrders();
    int getDayCounter() const { return dayCounter; }
    double getBalance() const;
    int getHappinessScore() const { return happinessScore; }
    int getTotalPlants();
    int getReadyPlantsCount();
};

#endif