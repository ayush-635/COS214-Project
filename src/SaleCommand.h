#ifndef SALECOMMAND_H
#define SALECOMMAND_H

class SaleCommand : TransactionCommand {

public:
	BankAccount* bank;
	Order* purchase;

	void execute();

	SaleCommand();
};

#endif
