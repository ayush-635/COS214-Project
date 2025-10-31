#include "StandardDelivery.h"
#include "../Order/Order.h"
#include <string>
#include <sstream>
using namespace std;

string StandardDelivery::deliver(Order o) {
    ostringstream oss;
    oss << "=== STANDARD DELIVERY ===" << endl;
    oss << "Delivery Method: Standard Shipping" << endl;
    oss << "Estimated Delivery Time: 5-7 business days" << endl;
    oss << "Order Total: R" << o.total() << endl;
    oss << "Delivery Cost: R50.00" << endl;
    oss << "Total Amount: R" << (o.total() + 50.00) << endl;
    oss << "Package will be shipped via standard courier" << endl;
    oss << "Tracking information will be sent via email" << endl;
    oss << "=========================" << endl;
    return oss.str();
}
