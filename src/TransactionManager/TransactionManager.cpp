#include "TransactionManager.h"

void TransactionManager::executeCommands()
{
	while(!commands.empty()){
		commands.front()->execute();
		commands.pop();
	}
}

void TransactionManager::addCommand(TransactionCommand *cmd)
{
	commands.push(cmd);
}

TransactionManager::TransactionManager()
{}
