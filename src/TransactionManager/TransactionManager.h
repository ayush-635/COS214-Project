#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

class TransactionManager {

public:
	stack<TransactionCommand*> history;

	void executeCommand(int cmd);

	TransactionManager();
};

#endif
