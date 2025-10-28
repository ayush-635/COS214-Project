#ifndef SALECOMMAND_H
#define SALECOMMAND_H
#include "TransactionCommand.h"
#include "BankAccount.h"
#include "Order.h"

class SaleCommand : TransactionCommand {

public:
	BankAccount* bank;
	Order* purchase;

	void execute();

	SaleCommand(BankAccount* bank, Order* pur);
};

#endif
