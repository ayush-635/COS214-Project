#ifndef CASHIER_H
#define CASHIER_H

#include "../StaffMember/StaffMember.h"

class Plant;

class Cashier : public StaffMember {
	private:
		std::string currPreference;
		Plant* currPlant;
	public:
		virtual ~Cashier(){};

		void tick(int time) override;

		void browse() override {}

		void receivePreference(const std::string& pref) override;

		void sendAdvice(const std::string& advice) override;

		bool checkStockLevel(Plant* plant);

		void requestNewStock(Plant* plant, int qty);
};

#endif
