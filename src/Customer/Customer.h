#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <unordered_map>
#include "../Colleague/Colleague.h"
#include "../Plant/Plant.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Customer : public Colleague {

private:
	std::unordered_map<int, std::string> preferences;
	int rand;
	std::string lastAdvice;
	std::vector<std::string> stockNotifications; 

public:
	bool requestSale(Plant* plant);
	std::string purchaseRandomPlants();
	std::string sendPreference();
	void storeAdvice(const std::string& advice);
	std::string receiveAdvice() override;
	Customer();
	void addStockNotification(const std::string& notification);
    std::vector<std::string> getStockNotifications() const;
    void clearStockNotifications();
};

#endif
