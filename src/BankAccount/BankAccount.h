#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <vector>
#include <string>
#include <sstream>

class BankAccount {

public:
	double balance;
	std::vector<std::string> transactionLog;

	void deposit(double amt, std::string desc);

	void withdraw(double amt, std::string desc);

	double getBalance();
	std::string getLog();
	static BankAccount* getInstance();

protected:
	BankAccount();

private:
	static BankAccount* onlyInstance;
};

#endif
