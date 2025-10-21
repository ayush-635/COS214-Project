#ifndef BUYASSETSCOMMAND_H
#define BUYASSETSCOMMAND_H

class BuyAssetsCommand : TransactionCommand {

private:
	BankAccount* bank;
	string item;
public:
	doble amount;

	void execute();

	BuyAssetsCommand();
};

#endif
