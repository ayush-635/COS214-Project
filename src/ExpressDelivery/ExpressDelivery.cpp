#include "ExpressDelivery.h"
#include "../Order/Order.h"
#include <string>
#include <sstream>
using namespace std;

string ExpressDelivery::deliver(Order o) {
    ostringstream oss;
    oss << "=== EXPRESS DELIVERY ===" << endl;
    oss << "Delivery Method: Express Shipping" << endl;
    oss << "Estimated Delivery Time: 1-2 business days" << endl;
    oss << "Order Total: R" << o.total() << endl;
    oss << "Delivery Cost: R150.00" << endl;
    oss << "Total Amount: R" << (o.total() + 150.00) << endl;
    oss << "PRIORITY PACKAGE - Expedited Processing" << endl;
    oss << "Same-day dispatch if ordered before 2 PM" << endl;
    oss << "Real-time tracking available" << endl;
    oss << "========================" << endl;
    return oss.str();
}
