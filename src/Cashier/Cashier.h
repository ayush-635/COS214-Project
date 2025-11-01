#ifndef CASHIER_H
#define CASHIER_H

#include "../StaffMember/StaffMember.h"
#include <string>

class Plant;
/**
 * @class Cashier
 * @brief A staff member specialized in handling sales and inventory checks.
 * The cashier uses the Inventory singleton to manage stock levels and sales.
 */

class Cashier : public StaffMember {
	private:
		/// @brief Current preference received from the plant.
		std::string currPreference;
		/// @brief Currently assigned plant (if any).
		Plant* currPlant = nullptr;
	public:
		/// @brief default destructor
		virtual ~Cashier()=default;

		/**
		* @brief Per-time-step update for the Cashier.
		* Prints the time spent alive.
		* @param time The amount of time to update.
		*/
		void tick(int time) override;

		/**
		* @brief Optional browsing action during duty. (Not used by Cashier)
		*/
		void browse() override {}

		/**
		* @brief Handle incoming preferences related to stock checks or sales.
		* Supported Formats:
		* - "CHECK:plant_name" to check stock level.
		* - "BUY:plant_name:<qty>" to attempt a sale.
		* Any other format is considered illegal.
		* @param pref The preference information received.
		*/
		void receivePreference(const std::string& pref) override;

		/**
		* @brief Sends advice to the user based on stock checks or sales through the mediator or to stdout.
		* @param advice The advice to send.
		*/
		void sendAdvice(const std::string& advice) override;

		/**
		* @brief Checks the stock level of a given plant.
		* @param plant The plant to check stock for.
		* @return true if stock is available, false otherwise.
		*/
		bool checkStockLevel(Plant* plant);

		/**
		* @brief Requests new stock for a given plant.
		* @param plant The plant to request stock for.
		* @param qty The quantity of stock to request.
		*/
		void requestNewStock(Plant* plant, int qty);
};

#endif
