#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include <queue>
#include "../TransactionCommand/TransactionCommand.h"

class TransactionManager {

public:
	std::queue<TransactionCommand*> commands;

	void executeCommands();

	void addCommand(TransactionCommand* cmd);

	TransactionManager();
};

#endif
