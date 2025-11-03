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
#include "../PlanterBox/PlanterBox.h"
#include "../PlantIterator/PlantIterator.h"
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
    void countHealthInSpace(PlantableArea* space, int& healthy, int& unhealthy, 
                        std::map<std::string, int>& plantTypes) const;
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
struct SpaceInfo {
    int index;
    int plantCount;
};

struct HealthCheckData {
    int totalPlants;
    int healthyCount;
    int unhealthyCount;
    std::map<std::string, int> plantTypes;
};

std::vector<SpaceInfo> getSpacesInfo() const {
    std::vector<SpaceInfo> result;
    for (size_t i = 0; i < spaces.size(); ++i) {
        SpaceInfo info;
        info.index = i + 1;
        //info.plantCount = countPlantsInSpace(spaces[i]);
        result.push_back(info);
    }
    return result;
}

HealthCheckData getHealthCheckData() {
    HealthCheckData data;
    data.totalPlants = 0;
    data.healthyCount = 0;
    data.unhealthyCount = 0;
    
    // Count plant types
    for (auto space : spaces) {
        countPlantTypesInSpace(space, data);
    }
    
    return data;
}

// Helper method for counting plant types
void countPlantTypesInSpace(PlantableArea* space, HealthCheckData& data) {
    for (int i = 0; i < 10; ++i) {
        PlantableArea* child = space->getChild(i);
        if (!child) break;
        
        PlanterBox* box = dynamic_cast<PlanterBox*>(child);
        if (box) {
            for (auto plant : box->getPlants()) {
                data.totalPlants++;
                data.plantTypes[plant->getName()]++;
                
                // Check health based on state
                std::string state = plant->getStateName();
                if (state == "Dying" || state == "Dead") {
                    data.unhealthyCount++;
                } else {
                    data.healthyCount++;
                }
            }
        }
        
        PlanterBoxCollection* coll = dynamic_cast<PlanterBoxCollection*>(child);
        if (coll) countPlantTypesInSpace(coll, data);
    }
}

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

int getWaterLevel() const { 
    return resourceManager ? resourceManager->getWaterLevel() : 1000; 
}

int getWaterCapacity() const { 
    return resourceManager ? resourceManager->getWaterCapacity() : 1000; 
}

int getFertilizerLevel() const { 
    return resourceManager ? resourceManager->getFertilizerLevel() : 500; 
}

int getFertilizerCapacity() const { 
    return resourceManager ? resourceManager->getFertilizerCapacity() : 500; 
}

int getOrderCount() const {
    return orders.size();
}

std::string getSpacesAsString() const;
std::string getHealthCheckAsString();
std::string getIteratorAsString();
std::string getInventoryAsString();
std::string getOrdersAsString();
};

#endif