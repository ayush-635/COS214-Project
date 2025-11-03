#ifndef GARDNER_H
#define GARDNER_H

#include "../StaffMember/StaffMember.h"
#include <string>

/**
 * @class Gardner
 * @brief A staff member specialized in plant selection based on customer preferences.
 * The gardener uses the Inventory singleton to find suitable plants.
 * This class assumes:
    * - Inventory::getAllPlantNames() returns the registered plant types
    * - Inventory::getPrototype(name) returns a Plant* prototype for the given name
    * - Plant::getPlantData() returns a shared_ptr<PlantData> containing plant attributes
 */
class Gardner : public StaffMember {
    private:
         /// @brief Current preference received from the plant.
        std::string currPreference;
        //static std::string findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare);
    public:
        /// @brief default destructor
        ~Gardner() override{};

        /**
        * @brief Per-time-step update for the Gardner.
        * Prints the time spent alive.
        * @param time The amount of time to update.
        */
        void tick(int time) override;

        /**
        * @brief Receives preference information about the plant.
        * @param pref The preference information received.
        */
        void receivePreference(const std::string& pref) override;

        /**
        * @brief Browses the inventory for plants matching the current preference.
        * Steps:
        * 1. Parse the stored prefernece for flags
        * 2. Query Inventory for all plant names
        * 3. For each plant that has stock:
        *    a. Get prototype and PlantData
        *    b. Check if PlantData matches preference flags
        *    c. If match, sendAdvice with plant name
        * If no matches found, a fallback message is sent.
        */
        void browse() override;

        /**
        * @brief Sends advice to the user based on the browsing results through the mediator or stdout.
        * @param advice The advice to send.
        */
        void sendAdvice(const std::string& advice) override;
};

#endif
