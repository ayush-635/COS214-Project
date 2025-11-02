/**
 * @file Customer.h
 * @author Ayush Sanjith
 * @brief Header file for the Customer class
 */

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

/**
 * @class Customer
 * @brief Represents a customer in the nursery system
 */
class Customer : public Colleague {

private:
    std::unordered_map<int, std::string> preferences; /**< Customer plant preferences */
    int rand; /**< Random seed for behavior */
    std::string lastAdvice; /**< Last advice received */
    std::vector<std::string> stockNotifications; /**< Stock notification messages */

public:
    /**
     * @brief Request to purchase a plant
     * @param plant Pointer to the plant
     * @return True if sale successful
     */
    bool requestSale(Plant* plant);

    /**
     * @brief Purchase random plants
     * @return Description of purchase
     */
    std::string purchaseRandomPlants();

    /**
     * @brief Send plant preference
     * @return Preference string
     */
    std::string sendPreference();

    /**
     * @brief Store advice received
     * @param advice Advice string to store
     */
    void storeAdvice(const std::string& advice);

    /**
     * @brief Receive advice override
     * @return Advice string
     */
    std::string receiveAdvice() override;

    /**
     * @brief Default constructor
     */
    Customer();

    /**
     * @brief Add stock notification
     * @param notification Notification message
     */
    void addStockNotification(const std::string& notification);

    /**
     * @brief Get stock notifications
     * @return Vector of notification strings
     */
    std::vector<std::string> getStockNotifications() const;

    /**
     * @brief Clear all stock notifications
     */
    void clearStockNotifications();
};

#endif