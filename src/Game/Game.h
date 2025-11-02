/**
 * @file Game.h
 * @author Ayush Sanjith
 * @brief Header file for the Game class - FACADE PATTERN
 */

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
#include "../ResourceManager/ResourceManager.h"
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

/**
 * @class Game
 * @brief Facade class that simplifies all subsystems
 */
class Game {
private:
    static Game* instance; /**< Singleton instance */
    
    // All subsystems (hidden from user)
    std::vector<PlantableArea*> spaces; /**< Plantable areas in the game */
    std::map<std::string, PlantFactory*> factories; /**< Plant factories */
    std::queue<Duty*> commandQueue; /**< Queue of duties to execute */
    BankAccount* bankAccount; /**< Bank account for transactions */
    TransactionManager* transactionManager; /**< Manages transactions */
    ResourceManager* resourceManager; /**< Manages water and fertilizer */
    HealthCheckVisitor* healthVisitor; /**< Visits plants for health checks */
    WateringStrategy* currentWateringStrategy; /**< Current watering strategy */
    InteractionManager* mediator; /**< Mediator for communication */
    Inventory* inventory; /**< Inventory management */
    InventoryObserver* inventoryObserver; /**< Observes inventory changes */
    
    std::vector<Customer*> customers; /**< List of customers */
    std::vector<Sales*> salesStaff; /**< List of sales staff */
    std::vector<Cashier*> cashiers; /**< List of cashiers */
    std::vector<Order*> orders; /**< List of orders */
    
    int dayCounter; /**< Current day count */
    int customerSpawnCounter; /**< Counter for customer spawning */
    int happinessScore; /**< Overall happiness score */
    
    /**
     * @brief Private constructor for singleton
     */
    Game();
    
    /**
     * @brief Destructor
     */
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
    /**
     * @brief Get singleton instance
     * @return Pointer to Game instance
     */
    static Game* getInstance();
    
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    
    /**
     * @brief Initialize the game
     */
    void initialize();
    
    // Building operations
    /**
     * @brief Build a new space
     * @param spaceType Type of space to build
     * @return True if successful
     */
    bool buildSpace(int spaceType);
    
    /**
     * @brief View all spaces
     */
    void viewAllSpaces();
    
    // Inventory operations
    /**
     * @brief Buy seeds
     * @param plantName Name of plant
     * @param quantity Quantity to buy
     * @return True if successful
     */
    bool buySeed(const std::string& plantName, int quantity);
    
    /**
     * @brief View inventory stock
     */
    void viewInventoryStock();
    
    /**
     * @brief Get inventory stock for a plant
     * @param plantName Name of plant
     * @return Stock quantity
     */
    int getInventoryStock(const std::string& plantName);
    
    // Resource operations
    /**
     * @brief View resource levels
     */
    void viewResources();
    
    /**
     * @brief Refill resources
     * @return True if successful
     */
    bool refillResources();
    
    // Planting operations
    /**
     * @brief Plant a seed
     * @param plantName Name of plant
     * @param spaceIndex Index of space
     * @param boxIndex Index of box
     * @return True if successful
     */
    bool plantSeed(const std::string& plantName, int spaceIndex, int boxIndex);
    
    /**
     * @brief Water plants
     * @param spaceIndex Index of space
     * @param boxIndex Index of box
     * @return True if successful
     */
    bool waterPlants(int spaceIndex, int boxIndex);
    
    /**
     * @brief Fertilize plants
     * @param spaceIndex Index of space
     * @param boxIndex Index of box
     * @return True if successful
     */
    bool fertilizePlants(int spaceIndex, int boxIndex);
    
    /**
     * @brief Execute all queued commands
     */
    void executeCommands();
    
    /**
     * @brief Change watering strategy
     * @param strategyType Type of strategy
     */
    void changeWateringStrategy(int strategyType);
    
    // Time progression
    /**
     * @brief Advance to next day
     */
    void advanceDay();
    
    /**
     * @brief Perform health check on all plants
     */
    void performHealthCheck();
    
    // Staff management
    /**
     * @brief Hire staff
     * @param staffType Type of staff
     * @return True if successful
     */
    bool hireStaff(int staffType);
    
    /**
     * @brief Trigger customer visit
     */
    void triggerCustomerVisit();
    
    // Iterator demonstration
    /**
     * @brief Demonstrate iterator pattern
     */
    void useIterator();
    
    // Status & Information
    /**
     * @brief Display game status
     */
    void displayGameStatus();
    
    /**
     * @brief View bank transaction log
     */
    void viewBankLog();
    
    /**
     * @brief View orders
     */
    void viewOrders();
    
    /**
     * @brief Get day counter
     * @return Current day count
     */
    int getDayCounter() const { return dayCounter; }
    
    /**
     * @brief Get current balance
     * @return Current balance
     */
    double getBalance() const;
    
    /**
     * @brief Get happiness score
     * @return Happiness score
     */
    int getHappinessScore() const { return happinessScore; }
    
    /**
     * @brief Get total plant count
     * @return Total plants
     */
    int getTotalPlants();
    
    /**
     * @brief Get ready plants count
     * @return Ready plants count
     */
    int getReadyPlantsCount();
};

#endif