#include "BuyAssetsCommand.h"

void BuyAssetsCommand::execute() {
	bank->withdraw(amount, item);
}

BuyAssetsCommand::BuyAssetsCommand(BankAccount* bank, std::string descr, double amt) {
	this->bank = bank;
	item = descr;
	amount = amt;
}
