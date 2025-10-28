#ifndef BUYASSETSCOMMAND_H
#define BUYASSETSCOMMAND_H
#include "TransactionCommand.h"
#include "BankAccount.h"
#include <string>

class BuyAssetsCommand : TransactionCommand {

private:
	BankAccount* bank;
	std::string item;
	double amount;
public:
	double amount;

	void execute();

	BuyAssetsCommand(BankAccount* b, std::string descr, double amt);
};

#endif
