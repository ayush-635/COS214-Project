#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <list>

class OrderItem;

class Order {
private:
    std::list<OrderItem*> items;

public:
    Order();
    ~Order();
    
    void addItem(OrderItem* item);
    double total() const;
    std::string getOrder() const;
    int getItemCount() const;
    const std::list<OrderItem*>& getItems() const;
};

#endif