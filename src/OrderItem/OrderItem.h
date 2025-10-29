#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>
using namespace std;

class OrderItem {
private:
    string name;
    double unitPrice;
    int qty;

public:
    double subtotal();
    int count();
    void list(int itemsOut);
    
    OrderItem();
};

#endif
