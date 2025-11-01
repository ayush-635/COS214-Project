#include "ExpressDelivery.h"
#include "../Order/Order.h"
#include <iostream>
using namespace std;

void ExpressDelivery::deliver(Order o) {
    cout << "=== EXPRESS DELIVERY ===" << endl;
    cout << "Delivery Method: Express Shipping" << endl;
    cout << "Estimated Delivery Time: 1-2 business days" << endl;
    cout << "Order Total: R" << o.total() << endl;
    cout << "Delivery Cost: R150.00" << endl;
    cout << "Total Amount: R" << (o.total() + 150.00) << endl;
    cout << "PRIORITY PACKAGE - Expedited Processing" << endl;
    cout << "Same-day dispatch if ordered before 2 PM" << endl;
    cout << "Real-time tracking available" << endl;
    cout << "========================" << endl;
}
