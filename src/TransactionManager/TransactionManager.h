/**
 * @file TransactionManager.h
 * @author Ayush Sanjith
 * @brief Header file for the TransactionManager class
 */

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include <queue>
#include "../TransactionCommand/TransactionCommand.h"

/**
 * @class TransactionManager
 * @brief Manages transaction commands
 */
class TransactionManager {

public:
    std::queue<TransactionCommand*> commands; /**< Queue of commands to execute */

    /**
     * @brief Execute all queued commands
     */
    void executeCommands();

    /**
     * @brief Add command to queue
     * @param cmd Command to add
     */
    void addCommand(TransactionCommand* cmd);

    /**
     * @brief Default constructor
     */
    TransactionManager();
};

#endif