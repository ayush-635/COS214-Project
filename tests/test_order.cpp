/* #include "doctest.h"
#include "../src/Order/Order.h"
#include "../src/OrderItem/OrderItem.h"

TEST_CASE("Order Total Calculation") {
    Order order;
    
    SUBCASE("Empty order") {
        CHECK(order.total() == doctest::Approx(0.0));
    }
    
    SUBCASE("Single item order") {
        OrderItem item("Book", 15.0, 2);
        order.addItem(&item);
        CHECK(order.total() == doctest::Approx(30.0));
    }
    
    SUBCASE("Multiple items order") {
        OrderItem item1("Book", 15.0, 2);
        OrderItem item2("Pen", 1.5, 10);
        order.addItem(&item1);
        order.addItem(&item2);
        CHECK(order.total() == doctest::Approx(45.0));
    }
}

TEST_CASE("Order Content") {
    Order order;
    
    SUBCASE("GetOrder returns item names") {
        OrderItem item1("Apple", 2.0, 3);
        OrderItem item2("Banana", 1.5, 2);
        
        order.addItem(&item1);
        order.addItem(&item2);
        
        std::string orderContent = order.getOrder();
        CHECK(orderContent.find("Apple") != std::string::npos);
        CHECK(orderContent.find("Banana") != std::string::npos);
    }
} */
