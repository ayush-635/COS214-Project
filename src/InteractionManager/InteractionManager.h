/**
 * @file InteractionManager.h
 * @author Ayush Sanjith
 * @brief Header file for the InteractionManager class
 */

#ifndef INTERACTIONMANAGER_H
#define INTERACTIONMANAGER_H
#include <string>
#include "../Mediator/Mediator.h"
#include <vector>
#include "../Sales/Sales.h"
#include "../Customer/Customer.h"

/**
 * @class InteractionManager
 * @brief Manages interactions between colleagues using mediator pattern
 */
class InteractionManager : public Mediator {
private:
    static InteractionManager* onlyInstance; /**< Singleton instance */

public:
    std::vector<Colleague*> list; /**< List of registered colleagues */

    /**
     * @brief Notify all customers
     * @param message Message to send
     */
    void notifyAllCustomers(const std::string& message);

    /**
     * @brief Notify a specific colleague
     * @param colleague Colleague to notify
     * @param msg Message to send
     */
    void notify(Colleague* colleague, std::string msg);

    /**
     * @brief Add a colleague to the manager
     * @param c Colleague to add
     */
    void addColleague(Colleague* c);

    /**
     * @brief Remove a colleague from the manager
     * @param c Colleague to remove
     */
    void remColleague(Colleague* c);

    /**
     * @brief Get singleton instance
     * @return Pointer to InteractionManager instance
     */
    static InteractionManager* getInstance();

    /**
     * @brief Default constructor
     */
    InteractionManager();
};

#endif