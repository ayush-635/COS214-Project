#ifndef GAME_H
#define GAME_H

#include "../Plant/Plant.h"
#include "../HealthCheckVisitor/HealthCheckVisitor.h"
#include <vector>
#include <memory>

class Game {
private:
    static Game* instance;
    std::vector<std::unique_ptr<Plant>> plants;
    HealthCheckVisitor healthVisitor;

	// NurseryManager* nurseryManager;
	// BankAccount* account;
    
    Game();

public:
    // Singleton pattern
    static Game* getInstance();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    
    // Plant management
    void addPlant(std::unique_ptr<Plant> plant);
    void removePlant(const std::string& plantId);
    Plant* getPlant(const std::string& plantId);
    
    // Game loop
    void update();
    void checkPlantConditions();
    
    // Player actions
    void waterPlant(const std::string& plantId);
    void fertilizePlant(const std::string& plantId);
    
    const std::vector<std::unique_ptr<Plant>>& getPlants() const { return plants; }
    void displayGameStatus() const;
};


#endif
