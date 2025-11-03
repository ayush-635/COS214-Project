#include "src/Game/Game.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class GameInterface {
private:
    Game* game;

public:
    GameInterface() : game(nullptr) {
        initializeGame();
    }

    ~GameInterface() {
        // Game is a singleton, so we don't delete it here
    }

private:
    void initializeGame() {
        game = Game::getInstance();
        game->initialize();
        
        std::cout << "\nPress Enter to continue...";
        std::cin.get();
    }

    void displayMainMenu() {
        std::cout << "\n╔════════════════════════════════════════════════════╗\n";
        std::cout << "║  DAY " << std::left << std::setw(3) << game->getDayCounter() 
                  << " | Balance: R" << std::setw(8) << game->getBalance() 
                  << " | Plants: " << std::setw(3) << game->getTotalPlants() 
                  << " | 😊: " << std::setw(3) << game->getHappinessScore() << "       ║\n";
        std::cout << "╚════════════════════════════════════════════════════╝\n";
        
        std::cout << "\n🏗️  BUILDING & VIEWING" << std::endl;
        std::cout << "  1. Build New Space" << std::endl;
        std::cout << "  2. View All Spaces" << std::endl;
        std::cout << "  3. View Inventory Stock" << std::endl;
        std::cout << "  4. View Order History" << std::endl;
        std::cout << "  5. View Resources (💧/🌿)" << std::endl;
        
        std::cout << "\n🌱 PLANT OPERATIONS" << std::endl;
        std::cout << "  6. Buy Seeds (Restock)" << std::endl;
        std::cout << "  7. Plant Seeds in Space" << std::endl;
        std::cout << "  8. Care for Plants (Water/Fertilize)" << std::endl;
        std::cout << "  9. Execute All Queued Commands" << std::endl;
        std::cout << " 10. Change Watering Strategy" << std::endl;
        std::cout << " 11. Health Check (Visitor)" << std::endl;
        std::cout << " 12. Use Plant Iterator" << std::endl;
        
        std::cout << "\n👥 STAFF & CUSTOMERS" << std::endl;
        std::cout << " 13. Hire New Staff" << std::endl;
        std::cout << " 14. Trigger Customer Visit" << std::endl;
        
        std::cout << "\n⏰ TIME & RESOURCES" << std::endl;
        std::cout << " 15. Refill Resources (R50)" << std::endl;
        std::cout << " 16. Advance Day (Grow Plants!)" << std::endl;
        std::cout << " 17. View Bank Log" << std::endl;
        std::cout << " 18. Game Status" << std::endl;
        std::cout << " 19. Exit Game" << std::endl;
        std::cout << "\nChoice: ";
    }

    void buildNewSpace() {
        std::cout << "\n═══ BUILD NEW SPACE ═══" << std::endl;
        std::cout << "1. Small Space (2 boxes) - R50" << std::endl;
        std::cout << "2. Medium Space (4 boxes) - R80" << std::endl;
        std::cout << "3. Big Space (nested, 6 boxes) - R120" << std::endl;
        std::cout << "Choose: ";
        
        int choice;
        std::cin >> choice;
        
        if (choice < 1 || choice > 3) {
            std::cout << "❌ Invalid choice!" << std::endl;
            return;
        }
        
        if (game->buildSpace(choice)) {
            std::string spaceName;
            switch (choice) {
                case 1: spaceName = "Small Space"; break;
                case 2: spaceName = "Medium Space"; break;
                case 3: spaceName = "Big Space"; break;
            }
            std::cout << "✅ " << spaceName << " built successfully!" << std::endl;
        } else {
            std::cout << "❌ Failed to build space! Check your balance." << std::endl;
        }
    }

    void buySeedsRestock() {
        std::cout << "\n═══ BUY SEEDS (Restock Inventory) ═══" << std::endl;
        
        std::vector<std::string> plantNames = {"Rose", "Tulip", "Lawn Grass", "Basil", "Mint"};
        
        std::cout << "Available seeds to buy:\n" << std::endl;
        
        for (size_t i = 0; i < plantNames.size(); ++i) {
            int stock = game->getInventoryStock(plantNames[i]);
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
        
        if (game->buySeed(plantName, qty)) {
            std::cout << "✅ Bought " << qty << " " << plantName << " seeds!" << std::endl;
            std::cout << "   New stock: " << game->getInventoryStock(plantName) << std::endl;
        } else {
            std::cout << "❌ Failed to buy seeds! Check your balance." << std::endl;
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
        std::cout << "\n═══ PLANT SEEDS ═══" << std::endl;
        
        std::vector<std::string> plantNames = {"Rose", "Tulip", "Lawn Grass", "Basil", "Mint"};
        
        std::cout << "Seeds in inventory:\n" << std::endl;
        bool hasSeeds = false;
        
        for (size_t i = 0; i < plantNames.size(); ++i) {
            int stock = game->getInventoryStock(plantNames[i]);
            std::cout << (i + 1) << ". " << std::left << std::setw(15) << plantNames[i] 
                      << "Stock: " << stock << std::endl;
            if (stock > 0) hasSeeds = true;
        }
        
        if (!hasSeeds) {
            std::cout << "\n❌ No seeds in inventory! Buy seeds first (option 6)." << std::endl;
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
        
        if (game->getInventoryStock(selectedPlant) <= 0) {
            std::cout << "❌ " << selectedPlant << " out of stock! Buy more seeds (option 6)." << std::endl;
            return;
        }
        
        std::cout << "Choose space (1-*): ";
        std::cin >> spaceChoice;
        std::cout << "Choose box index (0-9): ";
        std::cin >> boxIndex;
        
        if (game->plantSeed(selectedPlant, spaceChoice - 1, boxIndex)) {
            std::cout << "✅ Plant command queued for " << selectedPlant << "!" << std::endl;
            std::cout << "   Execute commands with option 9" << std::endl;
        } else {
            std::cout << "❌ Failed to plant seed! Check space index and inventory." << std::endl;
        }
    }

    void careForPlantsWithCommands() {
        std::cout << "\n═══ CARE FOR PLANTS ═══" << std::endl;
        std::cout << "💡 Water/Fertilizer resources are required!" << std::endl;
        std::cout << "1. Water Plants - R1 + uses 💧" << std::endl;
        std::cout << "2. Fertilize Plants - R3 + uses 🌿" << std::endl;
        std::cout << "Choose: ";
        
        int choice, spaceChoice, boxIndex;
        std::cin >> choice;
        
        std::cout << "Space (1-*): ";
        std::cin >> spaceChoice;
        std::cout << "Box index (0-9): ";
        std::cin >> boxIndex;
        
        bool success = false;
        
        if (choice == 1) {
            success = game->waterPlants(spaceChoice - 1, boxIndex);
            if (success) {
                std::cout << "✅ Water command queued!" << std::endl;
            }
        } else if (choice == 2) {
            success = game->fertilizePlants(spaceChoice - 1, boxIndex);
            if (success) {
                std::cout << "✅ Fertilize command queued!" << std::endl;
            }
        } else {
            std::cout << "❌ Invalid choice!" << std::endl;
            return;
        }
        
        if (!success) {
            std::cout << "❌ Failed to queue command!" << std::endl;
            std::cout << "   Check: resources, space, and balance" << std::endl;
        } else {
            std::cout << "   Execute with option 9" << std::endl;
        }
    }

    void changeWateringStrategy() {
        std::cout << "\n═══ WATERING STRATEGY ═══" << std::endl;
        std::cout << "1. Light (1 💧 per water)" << std::endl;
        std::cout << "2. Intermediate (3 💧 per water)" << std::endl;
        std::cout << "3. Heavy (5 💧 per water)" << std::endl;
        std::cout << "Choose: ";
        
        int choice;
        std::cin >> choice;
        
        game->changeWateringStrategy(choice);
        
        switch (choice) {
            case 1: std::cout << "✅ Light Watering Strategy (1 💧)" << std::endl; break;
            case 2: std::cout << "✅ Intermediate Watering Strategy (3 💧)" << std::endl; break;
            case 3: std::cout << "✅ Heavy Watering Strategy (5 💧)" << std::endl; break;
            default: std::cout << "✅ Default Watering (Intermediate, 3 💧)" << std::endl; break;
        }
    }

    void hireStaff() {
        std::cout << "\n═══ HIRE STAFF ═══" << std::endl;
        std::cout << "Staff are ESSENTIAL for selling plants!" << std::endl;
        std::cout << "\n1. Sales Staff - R100" << std::endl;
        std::cout << "   • Helps customers find plants" << std::endl;
        std::cout << "   • Earns 5% commission on sales" << std::endl;
        std::cout << "\n2. Cashier - R80" << std::endl;
        std::cout << "   • Processes payments" << std::endl;
        std::cout << "   • Required for all transactions" << std::endl;
        std::cout << "\nChoose: ";
        
        int choice;
        std::cin >> choice;
        
        if (choice < 1 || choice > 2) {
            std::cout << "❌ Invalid choice!" << std::endl;
            return;
        }
        
        if (game->hireStaff(choice)) {
            std::string staffType = (choice == 1) ? "Sales Staff" : "Cashier";
            std::cout << "✅ Hired " << staffType << "!" << std::endl;
            std::cout << "   They can now help with customer sales" << std::endl;
        } else {
            std::cout << "❌ Failed to hire staff! Check your balance." << std::endl;
        }
    }

    void displayFinalStatistics() {
        std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║           FINAL STATISTICS                     ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
        
        std::cout << "\n📅 Days played: " << game->getDayCounter() << std::endl;
        std::cout << "💰 Final balance: R" << game->getBalance() << std::endl;
        std::cout << "😊 Final happiness: " << game->getHappinessScore() << "/100" << std::endl;
        std::cout << "🌱 Total plants grown: " << game->getTotalPlants() << std::endl;
        std::cout << "💰 Ready to sell: " << game->getReadyPlantsCount() << std::endl;
        //std::cout << "🛒 Orders completed: " << game->getOrderCount() << std::endl;
        
        double profit = game->getBalance() - 1000.0;
        std::cout << "\n💵 Profit/Loss: R" << std::fixed << std::setprecision(2) << profit << std::endl;
        
        if (profit > 500) {
            std::cout << "\n🏆 EXCELLENT! Your nursery is thriving!" << std::endl;
        } else if (profit > 0) {
            std::cout << "\n👍 GOOD JOB! You made a profit!" << std::endl;
        } else if (profit > -200) {
            std::cout << "\n😐 NOT BAD! Almost broke even!" << std::endl;
        } else {
            std::cout << "\n💪 KEEP TRYING! Better luck next time!" << std::endl;
        }
        
        std::cout << "\n🌱 Thanks for playing Nursery Manager! 🌱\n" << std::endl;
    }

public:
    void run() {
        int choice;
        
        do {
            displayMainMenu();
            std::cin >> choice;
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "❌ Invalid input!" << std::endl;
                continue;
            }
            
            switch (choice) {
                case 1: buildNewSpace(); break;
                case 2: game->viewAllSpaces(); break;
                case 3: game->viewInventoryStock(); break;
                case 4: game->viewOrders(); break;
                case 5: game->viewResources(); break;
                case 6: buySeedsRestock(); break;
                case 7: plantSeedsInSpace(); break;
                case 8: careForPlantsWithCommands(); break;
                case 9: game->executeCommands(); break;
                case 10: changeWateringStrategy(); break;
                case 11: game->performHealthCheck(); break;
                case 12: game->useIterator(); break;
                case 13: hireStaff(); break;
                case 14: game->triggerCustomerVisit(); break;
                case 15: game->refillResources(); break;
                case 16: game->advanceDay(); break;
                case 17: game->viewBankLog(); break;
                case 18: game->displayGameStatus(); break;
                case 19: 
                    displayFinalStatistics();
                    break;
                default: 
                    std::cout << "❌ Invalid choice! Choose 1-19." << std::endl;
            }
            
            if (choice != 19) {
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }
            
        } while (choice != 19);
    }
};

int main() {
    GameInterface game;
    game.run();
    return 0;
}