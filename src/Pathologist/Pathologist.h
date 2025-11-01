#ifndef PATHOLOGIST_H
#define PATHOLOGIST_H

#include "../StaffMember/StaffMember.h"

/**
 * @class Pathologist
 * @brief A staff member specialized in diagnosing plant diseases.
 * Inherits from StaffMember.
 */
class Pathologist : public StaffMember {
    private:
        /// @brief Current preference received from the plant.
        std::string currPreference;
    public:
        /**
        * @brief Per-time-step update for the Pathologist.
        * Prints the time spent alive.
        * @param time The amount of time to update.
        */
        void tick(int time) override;

        /**
        * @brief Optional browsing action during duty.
        */
        void browse() override {}

        /**
        * @brief Receives preference information about the plant.
        * Analyzes the preference and sends advice accordingly.
        * @param pref The preference information received.
        */
        void receivePreference(const std::string& pref) override;
        
        /**
        * @brief Sends advice to the user based on the analysis through the mediator.
        * @param advice The advice to send.
        */
        void sendAdvice(const std::string& advice) override;
};

#endif
