/**
 * @file BankAccount.h
 * @author Ayush Sanjith
 * @brief Header file for the BankAccount class
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <vector>
#include <string>
#include <sstream>

/**
 * @class BankAccount
 * @brief Manages the bank account and transaction logging
 */
class BankAccount {

public:
    double balance;                         /**< Current account balance */
    std::vector<std::string> transactionLog; /**< Log of all transactions */

    /**
     * @brief Deposit money into the account
     * @param amt Amount to deposit
     * @param desc Description of the deposit
     */
    void deposit(double amt, std::string desc);

    /**
     * @brief Withdraw money from the account
     * @param amt Amount to withdraw
     * @param desc Description of the withdrawal
     */
    void withdraw(double amt, std::string desc);

    /**
     * @brief Get the current balance
     * @return Current account balance
     */
    double getBalance();

    /**
     * @brief Get the transaction log
     * @return String containing all transactions
     */
    std::string getLog();

    /**
     * @brief Get the singleton instance
     * @return Pointer to the BankAccount instance
     */
    static BankAccount* getInstance();

protected:
    /**
     * @brief Protected constructor for singleton pattern
     */
    BankAccount();

private:
    static BankAccount* onlyInstance; /**< Singleton instance pointer */
};

#endif
