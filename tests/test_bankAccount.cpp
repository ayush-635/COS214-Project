#include "doctest.h"
#include "../src/BankAccount/BankAccount.h"
#include <sstream>

TEST_CASE("BankAccount Singleton Pattern") {
    SUBCASE("GetInstance returns same instance") {
        BankAccount* account1 = BankAccount::getInstance();
        BankAccount* account2 = BankAccount::getInstance();
        CHECK(account1 == account2);
    }
    
    SUBCASE("Initial balance is zero") {
        BankAccount* account = BankAccount::getInstance();
        CHECK(account->getBalance() == 0.0);
    }
}

TEST_CASE("BankAccount Deposit Operations") {
    BankAccount* account = BankAccount::getInstance();
    double initialBalance = account->getBalance();
    
    SUBCASE("Single deposit") {
        account->deposit(100.0, "Test deposit");
        CHECK(account->getBalance() == doctest::Approx(initialBalance + 100.0));
    }
    
    SUBCASE("Multiple deposits") {
        account->deposit(50.0, "First deposit");
        account->deposit(25.5, "Second deposit");
        CHECK(account->getBalance() == doctest::Approx(initialBalance + 75.5));
    }
    
    SUBCASE("Zero deposit") {
        account->deposit(0.0, "Zero deposit");
        CHECK(account->getBalance() == doctest::Approx(initialBalance));
    }
}

TEST_CASE("BankAccount Withdrawal Operations") {
    BankAccount* account = BankAccount::getInstance();
    account->deposit(200.0, "Setup deposit");
    double balanceAfterDeposit = account->getBalance();
    
    SUBCASE("Single withdrawal") {
        account->withdraw(50.0, "Test withdrawal");
        CHECK(account->getBalance() == doctest::Approx(balanceAfterDeposit - 50.0));
    }
    
    SUBCASE("Multiple withdrawals") {
        account->withdraw(30.0, "First withdrawal");
        account->withdraw(20.5, "Second withdrawal");
        CHECK(account->getBalance() == doctest::Approx(balanceAfterDeposit - 50.5));
    }
}

TEST_CASE("BankAccount Transaction Log") {
    BankAccount* account = BankAccount::getInstance();
    
    SUBCASE("Log contains deposit information") {
        account->deposit(100.0, "Salary");
        std::string log = account->getLog();
        CHECK(log.find("Deposit") != std::string::npos);
        CHECK(log.find("100") != std::string::npos);
        CHECK(log.find("Salary") != std::string::npos);
    }
    
    SUBCASE("Log contains withdrawal information") {
        account->withdraw(50.0, "Rent");
        std::string log = account->getLog();
        CHECK(log.find("Withdrawal") != std::string::npos);
        CHECK(log.find("50") != std::string::npos);
        CHECK(log.find("Rent") != std::string::npos);
    }
}