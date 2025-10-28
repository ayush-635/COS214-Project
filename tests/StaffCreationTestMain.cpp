#include <iostream>
#include <vector>

struct Plant {};

#include "../src/StaffMember/StaffMember.h"
#include "../src/Sales/Sales.h"
#include "../src/Gardner/Gardner.h"
#include "../src/Pathologist/Pathologist.h"
#include "../src/Cashier/Cashier.h"

static void runScenario(StaffMember& sm, const char* name) {
    std::cout << "== " << name << " doDuty() ==" << std::endl;
    sm.doDuty();
    std::cout << std::endl;
}

int main() {
    std::cout << "Running Staff creation test..." << std::endl << std::endl;

    Sales sales;
    Gardner gardner;
    Pathologist pathologist;
    Cashier cashier;

    std::vector<StaffMember*> team;
    team.push_back(&sales);
    team.push_back(&gardner);
    team.push_back(&pathologist);
    team.push_back(&cashier);

    for (std::size_t i = 0; i < team.size(); ++i) {
        const char* name = (team[i] == &sales) ? "Sales" :
                           (team[i] == &gardner) ? "Gardner" :
                           (team[i] == &pathologist) ? "Pathologist" :
                           "Cashier";
        runScenario(*team[i], name);
    }

    Plant p;
    bool available = cashier.checkStockLevel(&p);
    cashier.requestNewStock(&p, 3);
    std::cout << "Cashier checkStockLevel returned: " << (available ? "true" : "false") << std::endl;
    return 0;
}
