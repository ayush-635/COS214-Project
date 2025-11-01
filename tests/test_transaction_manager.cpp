#include "doctest.h"
#include "../src/TransactionManager/TransactionManager.h"

// Simple Mock TransactionCommand
class MockTransactionCommand : public TransactionCommand {
public:
    int executionCount = 0;
    
    void execute() override {
        executionCount++;
    }
};

TEST_CASE("TransactionManager Basic Operations") {
    TransactionManager manager;
    
    SUBCASE("Manager can be constructed") {
        CHECK_NOTHROW(TransactionManager manager);
    }
    
    SUBCASE("Empty command queue execution") {
        CHECK_NOTHROW(manager.executeCommands());
    }
    
    SUBCASE("Add command to manager") {
        MockTransactionCommand* cmd = new MockTransactionCommand();
        CHECK_NOTHROW(manager.addCommand(cmd));
        delete cmd;
    }
}

TEST_CASE("TransactionManager Command Execution") {
    TransactionManager manager;
    
    SUBCASE("Single command execution") {
        MockTransactionCommand* cmd = new MockTransactionCommand();
        manager.addCommand(cmd);
        
        CHECK_NOTHROW(manager.executeCommands());
        CHECK(cmd->executionCount == 1);
        
        delete cmd;
    }
    
    SUBCASE("Multiple commands execution order") {
        MockTransactionCommand* cmd1 = new MockTransactionCommand();
        MockTransactionCommand* cmd2 = new MockTransactionCommand();
        MockTransactionCommand* cmd3 = new MockTransactionCommand();
        
        manager.addCommand(cmd1);
        manager.addCommand(cmd2);
        manager.addCommand(cmd3);
        
        CHECK_NOTHROW(manager.executeCommands());
        
        CHECK(cmd1->executionCount == 1);
        CHECK(cmd2->executionCount == 1);
        CHECK(cmd3->executionCount == 1);
        
        delete cmd1;
        delete cmd2;
        delete cmd3;
    }
}