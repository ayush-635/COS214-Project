#include <iostream>
#include <vector>

#include "../src/StaffMember/StaffMember.h"
#include "../src/Sales/Sales.h"
#include "../src/Gardner/Gardner.h"
#include "../src/Pathologist/Pathologist.h"
#include "../src/Cashier/Cashier.h"

static void run(StaffMember& s, const char* name) {
    std::cout << "\n== Testing: " << name << " ==\n";
    s.doDuty(5);
    std::cout << "totalTime = " << s.totalTime() << "\n";
}

int main() {
    std::cout << "Staff Member Creation Test: \n";

    Sales sales;
    Gardner gardner;
    Pathologist pathologist;
    Cashier cashier;

    std::vector<StaffMember*> staff = {
        &sales,
        &gardner,
        &pathologist,
        &cashier
    };

    for (StaffMember* s : staff) {
        const char* n =
            (s == &sales)       ? "Sales" :
            (s == &gardner)     ? "Gardner" :
            (s == &pathologist) ? "Pathologist" :
                                  "Cashier";
        run(*s, n);
    }

    std::cout << "\n=== DONE ===\n";
    return 0;
}
