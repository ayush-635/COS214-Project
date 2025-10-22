#ifndef TRANSACTIONLOGGER_H
#define TRANSACTIONLOGGER_H

class TransactionLogger : Observer2 {


public:
	void update(string event, double amount);
};

#endif
