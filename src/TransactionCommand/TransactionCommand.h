#ifndef TRANSACTIONCOMMAND_H
#define TRANSACTIONCOMMAND_H

class TransactionCommand {


public:
	virtual void execute()=0;
	virtual ~TransactionCommand()=default;
};

#endif
