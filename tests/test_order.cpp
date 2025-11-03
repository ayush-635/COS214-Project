#include "doctest.h"
#include "../src/Order/Order.h"
#include "../src/OrderItem/OrderItem.h"
#include <sstream>

TEST_CASE("Order Constructor and Destructor") {
    SUBCASE("Default constructor creates empty order") {
        Order order;
        CHECK(order.getItemCount() == 0);
        CHECK(order.total() == doctest::Approx(0.0));
    }
    
    SUBCASE("Destructor cleans up items") {
        // This would need memory leak detection to properly test
        // For now, we'll verify the order can be destroyed without crashes
        Order* order = new Order();
        OrderItem* item = new OrderItem("Test", 10.0, 1);
        order->addItem(item);
        delete order; // Should not crash and should clean up memory
    }
}

TEST_CASE("Order addItem Method") {
    SUBCASE("Add single item increases count") {
        Order order;
        OrderItem item("Book", 15.0, 1);
        
        order.addItem(&item);
        
        CHECK(order.getItemCount() == 1);
    }
    
    SUBCASE("Add multiple items increases count correctly") {
        Order order;
        OrderItem item1("Book", 15.0, 1);
        OrderItem item2("Pen", 1.5, 2);
        
        order.addItem(&item1);
        order.addItem(&item2);
        
        CHECK(order.getItemCount() == 2);
    }
    
    SUBCASE("Added items appear in getItems list") {
        Order order;
        OrderItem item1("Item1", 10.0, 1);
        OrderItem item2("Item2", 20.0, 1);
        
        order.addItem(&item1);
        order.addItem(&item2);
        
        const std::list<OrderItem*>& items = order.getItems();
        CHECK(items.size() == 2);
        
        // Check that both items are in the list
        bool foundItem1 = false;
        bool foundItem2 = false;
        for (const auto& item : items) {
            if (item == &item1) foundItem1 = true;
            if (item == &item2) foundItem2 = true;
        }
        CHECK(foundItem1 == true);
        CHECK(foundItem2 == true);
    }
}

TEST_CASE("Order total Method") {
    SUBCASE("Empty order returns zero") {
        Order order;
        CHECK(order.total() == doctest::Approx(0.0));
    }
    
    SUBCASE("Single item order calculates correctly") {
        Order order;
        OrderItem item("Book", 15.0, 2); // 15.0 * 2 = 30.0
        
        order.addItem(&item);
        
        CHECK(order.total() == doctest::Approx(30.0));
    }
    
    SUBCASE("Multiple items order calculates sum correctly") {
        Order order;
        OrderItem item1("Book", 15.0, 2);  // 30.0
        OrderItem item2("Pen", 1.5, 10);   // 15.0
        OrderItem item3("Notebook", 5.0, 3); // 15.0
        
        order.addItem(&item1);
        order.addItem(&item2);
        order.addItem(&item3);
        
        CHECK(order.total() == doctest::Approx(60.0)); // 30 + 15 + 15
    }
    
    SUBCASE("Order with zero quantity items") {
        Order order;
        OrderItem item("Free Item", 10.0, 0); // Should be 0
        
        order.addItem(&item);
        
        CHECK(order.total() == doctest::Approx(0.0));
    }
    
    SUBCASE("Order with zero price items") {
        Order order;
        OrderItem item("Free Item", 0.0, 5); // Should be 0
        
        order.addItem(&item);
        
        CHECK(order.total() == doctest::Approx(0.0));
    }
}

TEST_CASE("Order getOrder Method") {
    SUBCASE("Empty order returns proper format") {
        Order order;
        std::string result = order.getOrder();
        
        CHECK(result.find("ORDER CONTENTS:") != std::string::npos);
        CHECK(result.find("===============") != std::string::npos);
        CHECK(result.find("Subtotal: R0") != std::string::npos);
    }
    
    SUBCASE("Single item order shows item details") {
        Order order;
        OrderItem item("Apple", 2.0, 3); // R6 total
        
        order.addItem(&item);
        std::string result = order.getOrder();
        
        CHECK(result.find("Apple") != std::string::npos);
        CHECK(result.find("R6") != std::string::npos);
        CHECK(result.find("Subtotal: R6") != std::string::npos);
    }
    
    SUBCASE("Multiple items order shows all items and correct total") {
        Order order;
        OrderItem item1("Apple", 2.0, 3);  // R6
        OrderItem item2("Banana", 1.5, 2); // R3
        
        order.addItem(&item1);
        order.addItem(&item2);
        std::string result = order.getOrder();
        
        CHECK(result.find("Apple") != std::string::npos);
        CHECK(result.find("Banana") != std::string::npos);
        CHECK(result.find("R6") != std::string::npos);
        CHECK(result.find("R3") != std::string::npos);
        CHECK(result.find("Subtotal: R9") != std::string::npos);
    }
    
    SUBCASE("Order formatting includes item numbers") {
        Order order;
        OrderItem item1("First", 1.0, 1);
        OrderItem item2("Second", 2.0, 1);
        
        order.addItem(&item1);
        order.addItem(&item2);
        std::string result = order.getOrder();
        
        CHECK(result.find("1.") != std::string::npos);
        CHECK(result.find("2.") != std::string::npos);
    }
}

TEST_CASE("Order getItemCount Method") {
    SUBCASE("New order has zero items") {
        Order order;
        CHECK(order.getItemCount() == 0);
    }
    
    SUBCASE("Item count increases with each addition") {
        Order order;
        
        CHECK(order.getItemCount() == 0);
        
        OrderItem item1("Item1", 1.0, 1);
        order.addItem(&item1);
        CHECK(order.getItemCount() == 1);
        
        OrderItem item2("Item2", 2.0, 1);
        order.addItem(&item2);
        CHECK(order.getItemCount() == 2);
    }
    
    SUBCASE("Adding same item multiple times increases count") {
        Order order;
        OrderItem item("Same Item", 1.0, 1);
        
        order.addItem(&item);
        CHECK(order.getItemCount() == 1);
        
        order.addItem(&item); // Adding same item again
        CHECK(order.getItemCount() == 2);
    }
}

TEST_CASE("Order getItems Method") {
    SUBCASE("Empty order returns empty list") {
        Order order;
        const std::list<OrderItem*>& items = order.getItems();
        
        CHECK(items.empty() == true);
        CHECK(items.size() == 0);
    }
    
    SUBCASE("Returns correct items in correct order") {
        Order order;
        OrderItem item1("First", 1.0, 1);
        OrderItem item2("Second", 2.0, 1);
        OrderItem item3("Third", 3.0, 1);
        
        order.addItem(&item1);
        order.addItem(&item2);
        order.addItem(&item3);
        
        const std::list<OrderItem*>& items = order.getItems();
        
        CHECK(items.size() == 3);
        
        // Verify all items are present
        auto it = items.begin();
        CHECK(*it == &item1);
        ++it;
        CHECK(*it == &item2);
        ++it;
        CHECK(*it == &item3);
    }
    
    SUBCASE("Returned list is const reference") {
        Order order;
        OrderItem item("Test", 1.0, 1);
        order.addItem(&item);
        
        const std::list<OrderItem*>& items = order.getItems();
        
        // This should compile - we're testing the return type is const
        CHECK(items.front() == &item);
    }
}

TEST_CASE("Order Integration Tests") {
    SUBCASE("Complete order lifecycle") {
        Order order;
        
        // Start empty
        CHECK(order.getItemCount() == 0);
        CHECK(order.total() == doctest::Approx(0.0));
        
        // Add items
        OrderItem item1("Laptop", 1000.0, 1);
        OrderItem item2("Mouse", 25.0, 2);
        OrderItem item3("Keyboard", 75.0, 1);
        
        order.addItem(&item1);
        order.addItem(&item2);
        order.addItem(&item3);
        
        // Verify final state
        CHECK(order.getItemCount() == 3);
        CHECK(order.total() == doctest::Approx(1125.0)); // 1000 + 50 + 75
        
        std::string orderText = order.getOrder();
        CHECK(orderText.find("Laptop") != std::string::npos);
        CHECK(orderText.find("Mouse") != std::string::npos);
        CHECK(orderText.find("Keyboard") != std::string::npos);
        CHECK(orderText.find("Subtotal: R1125") != std::string::npos);
    }
}