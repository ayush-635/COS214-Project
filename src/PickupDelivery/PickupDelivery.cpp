#include "PickupDelivery.h"
#include "../Order/Order.h"
#include <iostream>
using namespace std;

void PickupDelivery::deliver(Order o) {
    cout << "=== PICKUP DELIVERY ===" << endl;
    cout << "Delivery Method: Customer Pickup" << endl;
    cout << "Pickup Location: Main Nursery - 123 Garden St" << endl;
    cout << "Order Total: R" << o.total() << endl;
    cout << "Delivery Cost: R0.00 (FREE PICKUP)" << endl;
    cout << "Total Amount: R" << o.total() << endl;
    cout << "Order will be ready for pickup in 2-4 hours" << endl;
    cout << "Please bring ID and order confirmation" << endl;
    cout << "Pickup Hours: Mon-Sat 8AM-6PM, Sun 9AM-4PM" << endl;
    cout << "========================" << endl;
}
