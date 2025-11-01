#ifndef ORDERITEM_H
#define ORDERITEM_H
#include <string>
#include <sstream>
#include "../Pot/Pot.h"

class OrderItem {
private:
    double unitPrice;
    int qty;
    Pot* pot;

public:
    std::string name;
    
    OrderItem();
    OrderItem(std::string name, double price, int qty);
    ~OrderItem();
    
    double subtotal();
    std::string getInfo();
    
    void addPot();
    bool hasPot() const { return pot != nullptr; }
    Pot* getPot() const { return pot; }
};

#endif