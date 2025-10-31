#ifndef BUYASSETSCOMMAND_H
#define BUYASSETSCOMMAND_H
#include "../TransactionCommand/TransactionCommand.h"
#include "../BankAccount/BankAccount.h"
#include <string>

class BuyAssetsCommand : public TransactionCommand {

private:
	BankAccount* bank;
	std::string item;

public:
	double amount;

	void execute();

	BuyAssetsCommand(BankAccount* b, std::string descr, double amt);
};

#endif
