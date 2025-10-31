#include "PickupDelivery.h"
#include "../Order/Order.h"
#include <string>
#include <sstream>
using namespace std;

string PickupDelivery::deliver(Order o) {
    ostringstream oss;
    oss << "=== PICKUP DELIVERY ===" << endl;
    oss << "Delivery Method: Customer Pickup" << endl;
    oss << "Pickup Location: Main Nursery - 123 Garden St" << endl;
    oss << "Order Total: R" << o.total() << endl;
    oss << "Delivery Cost: R0.00 (FREE PICKUP)" << endl;
    oss << "Total Amount: R" << o.total() << endl;
    oss << "Order will be ready for pickup in 2-4 hours" << endl;
    oss << "Please bring ID and order confirmation" << endl;
    oss << "Pickup Hours: Mon-Sat 8AM-6PM, Sun 9AM-4PM" << endl;
    oss << "========================" << endl;
    return oss.str();
}
