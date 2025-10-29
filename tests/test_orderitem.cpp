#include "doctest.h"
#include "../src/OrderItem/OrderItem.h"

TEST_CASE("OrderItem Calculations") {
    SUBCASE("Subtotal calculation") {
        OrderItem item("Test Item", 10.0, 3);
        CHECK(item.subtotal() == doctest::Approx(30.0));
    }
    
    SUBCASE("Zero quantity") {
        OrderItem item("Test Item", 15.5, 0);
        CHECK(item.subtotal() == doctest::Approx(0.0));
    }
    
    SUBCASE("Single quantity") {
        OrderItem item("Single Item", 25.0, 1);
        CHECK(item.subtotal() == doctest::Approx(25.0));
    }
}

TEST_CASE("OrderItem Information") {
    SUBCASE("GetInfo contains all details") {
        OrderItem item("Apple", 2.5, 4);
        std::string info = item.getInfo();
        
        CHECK(info.find("Apple") != std::string::npos);
        CHECK(info.find("2.5") != std::string::npos);
        CHECK(info.find("4") != std::string::npos);
        CHECK(info.find("10") != std::string::npos);
    }
}