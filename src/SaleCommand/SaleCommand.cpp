#include "SaleCommand.h"

void SaleCommand::execute() {
	bank->deposit(purchase->total(), purchase->getOrder());
}

SaleCommand::SaleCommand(BankAccount *bank, Order *pur)
{
	this->bank = bank;
	this->purchase = pur;
}
