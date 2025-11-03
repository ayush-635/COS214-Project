/**
 * @file SaleCommand.h
 * @author Ayush Sanjith
 * @brief Header file for the SaleCommand class
 */

#ifndef SALECOMMAND_H
#define SALECOMMAND_H
#include "../TransactionCommand/TransactionCommand.h"
#include "../BankAccount/BankAccount.h"
#include "../Order/Order.h"

/**
 * @class SaleCommand
 * @brief Command for executing sales transactions
 */
class SaleCommand : public TransactionCommand {

public:
    BankAccount* bank;/**< Pointer to the bank account for the transaction */
    Order* purchase;/**< Pointer to the order being processed */

    /**
     * @brief Execute the sale command
     */
    void execute();

    /**
     * @brief Constructor for SaleCommand
     * @param bank Pointer to the bank account
     * @param pur Pointer to the purchase order
     */
    SaleCommand(BankAccount* bank, Order* pur);
};

#endif