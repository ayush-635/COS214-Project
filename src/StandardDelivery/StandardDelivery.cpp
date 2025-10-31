#include "../StandardDelivery/StandardDelivery.h"
#include "../Order/Order.h"
#include <iostream>
using namespace std;

void StandardDelivery::deliver(Order o) {
    cout << "=== STANDARD DELIVERY ===" << endl;
    cout << "Delivery Method: Standard Shipping" << endl;
    cout << "Estimated Delivery Time: 5-7 business days" << endl;
    cout << "Order Total: R" << o.total() << endl;
    cout << "Delivery Cost: R50.00" << endl;
    cout << "Total Amount: R" << (o.total() + 50.00) << endl;
    cout << "Package will be shipped via standard courier" << endl;
    cout << "Tracking information will be sent via email" << endl;
    cout << "=========================" << endl;
}
