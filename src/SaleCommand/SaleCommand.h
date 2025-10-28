#ifndef SALECOMMAND_H
#define SALECOMMAND_H
#include "../TransactionCommand/TransactionCommand.h"
#include "../BankAccount/BankAccount.h"
#include "../Order/Order.h"

class SaleCommand : public TransactionCommand {

public:
	BankAccount* bank;
	Order* purchase;

	void execute();

	SaleCommand(BankAccount* bank, Order* pur);
};

#endif
