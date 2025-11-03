#include "BankAccount.h"

BankAccount* BankAccount::onlyInstance = 0;
void BankAccount::deposit(double amt, std::string desc) {
	balance+=amt;
	std::ostringstream oss;
	oss<< "Deposit\nAmount: R"<<amt<<"\nDescription: "<<desc<<"\n";
	transactionLog.push_back(oss.str());
}

void BankAccount::withdraw(double amt, std::string desc) {
	balance-=amt;
	std::ostringstream oss;
	oss<< "Withdrawal\nAmount: R"<<amt<<"\nDescription: "<<desc<<"\n";
	transactionLog.push_back(oss.str());
}

BankAccount::BankAccount() {
	balance = 0;
}

double BankAccount::getBalance()
{
    return balance;
}

std::string BankAccount::getLog()
{
	std::string ret = "";
    for(std::vector<std::string>::reverse_iterator it=transactionLog.rbegin(); it!=transactionLog.rend(); ++it){
		ret+=*it+"\n";
	}
	return ret;
}

BankAccount* BankAccount::getInstance() {
    static BankAccount instance;
    return &instance;
}
