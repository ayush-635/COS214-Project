/**
 * @file BuyAssetsCommand.h
 * @author Ayush Sanjith
 * @brief Header file for the BuyAssetsCommand class
 */

#ifndef BUYASSETSCOMMAND_H
#define BUYASSETSCOMMAND_H
#include "../TransactionCommand/TransactionCommand.h"
#include "../BankAccount/BankAccount.h"
#include <string>

/**
 * @class BuyAssetsCommand
 * @brief Command for buying assets
 */
class BuyAssetsCommand : public TransactionCommand {

private:
    BankAccount* bank; /**< Pointer to the bank account */
    std::string item;  /**< Item to be purchased */

public:
    double amount; /**< Amount to spend */

    /**
     * @brief Execute the buy command
     */
    void execute();

    /**
     * @brief Constructor
     * @param b Pointer to bank account
     * @param descr Description of item
     * @param amt Amount to spend
     */
    BuyAssetsCommand(BankAccount* b, std::string descr, double amt);
};

#endif