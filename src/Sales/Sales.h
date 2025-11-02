#ifndef SALES_H
#define SALES_H
#include "../StaffMember/StaffMember.h"
#include <string>
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include "../PlantData/PlantData.h"
#include "../Mediator/Mediator.h"
#include "../StaffMember/StaffMember.h"
#include <string>
#include <vector>

/**
 * @class Sales
 * @brief A staff member specialized in assisting customers with plant selection based on preferences.
 * The sales staff uses the Inventory singleton to find suitable plants.
 */
class Sales : public StaffMember {
    private:
        /// @brief Current preference received from the plant.
        std::string currPreference;
        //std::string findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare);

    public:
        /// @brief default constructor
        Sales();

        /// @brief default destructor
        virtual ~Sales(){};

        /**
        * @brief Per-time-step update for the Sales.
        * Prints the time spent alive.
        * @param time The amount of time to update.
        */
        void tick(int time);

        /**
        * @brief Finds a plant matching the given preference flags.
        * Workflow:
        * 1. Query Inventory for all plant names
        * 2. For each plant that has stock:
        *    a. Get prototype and PlantData
        *    b. Check if PlantData matches preference flags
        *    c. Check stock > 0
        * 3. If match found, return plant name and stock
        * 4. If no matches found, return fallback message.
        * @param outside Whether the plant should be suitable for outside.
        * @param lowLight Whether the plant should be suitable for low light.
        * @param lowWater Whether the plant should be suitable for low water.
        * @param brightColour Whether the plant should have bright colors.
        * @param lowCare Whether the plant should require low maintenance.
        * @return The name of the matching plant or a fallback message.
        */
        std::string findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare);

        /**
        * @brief Receives preference information about the plant.
        * @param pref The preference information received.
         */
        void receivePreference(const std::string& pref);

        /**
        * @brief Parses the current preference and browses the inventory for matching plants.
        * Matching advice is sent via sendAdvice().
        */
        void browse();

        /**
        * @brief Sends advice to the customer.
        * @param advice The advice message to send.
        */
        void sendAdvice(const std::string& advice);

        /**
        * @brief Handles the purchase of a specified number of plants.
        * @param numPlants The number of plants to purchase.
        * @return A message indicating the result of the purchase.
        */
        std::string handlePurchase(int numPlants);
};

#endif
