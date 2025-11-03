#include "doctest.h"
#include "../src/Order/Order.h"
#include "../src/OrderItem/OrderItem.h"
#include "../src/DeliveryStrategy/DeliveryStrategy.h"
#include "../src/StandardDelivery/StandardDelivery.h"
#include "../src/ExpressDelivery/ExpressDelivery.h"
#include "../src/PickupDelivery/PickupDelivery.h"

TEST_SUITE("Delivery Strategy Pattern Tests") {
    
    TEST_CASE("StandardDelivery - Basic Functionality") {
        Order order;
        OrderItem* item1 = new OrderItem("Rose Plant", 50.0, 2);
        OrderItem* item2 = new OrderItem("Tulip Plant", 40.0, 1);
        order.addItem(item1);
        order.addItem(item2);
        
        StandardDelivery standardDelivery;
        
        SUBCASE("Order total is correct") {
            CHECK(order.total() == doctest::Approx(140.0));
        }
        
        SUBCASE("Order has correct item count") {
            CHECK(order.getItemCount() == 2);
        }
        
        SUBCASE("StandardDelivery cost is R50") {
            CHECK(standardDelivery.getDeliveryCost() == doctest::Approx(50.0));
        }
        
        SUBCASE("StandardDelivery type is correct") {
            CHECK(standardDelivery.getDeliveryType() == "Standard Delivery");
        }
        
        SUBCASE("StandardDelivery delivers without crashing") {
            CHECK_NOTHROW(standardDelivery.deliver(order));
        }
        
        SUBCASE("Total with delivery is correct") {
            double totalWithDelivery = order.total() + standardDelivery.getDeliveryCost();
            CHECK(totalWithDelivery == doctest::Approx(190.0));
        }
    }
    
    TEST_CASE("ExpressDelivery - Basic Functionality") {
        Order order;
        OrderItem* item = new OrderItem("Basil Plant", 25.0, 3);
        order.addItem(item);
        
        ExpressDelivery expressDelivery;
        
        SUBCASE("Order total is correct") {
            CHECK(order.total() == doctest::Approx(75.0));
        }
        
        SUBCASE("Order has correct item count") {
            CHECK(order.getItemCount() == 1);
        }
        
        SUBCASE("ExpressDelivery cost is R150") {
            CHECK(expressDelivery.getDeliveryCost() == doctest::Approx(150.0));
        }
        
        SUBCASE("ExpressDelivery type is correct") {
            CHECK(expressDelivery.getDeliveryType() == "Express Delivery");
        }
        
        SUBCASE("ExpressDelivery delivers without crashing") {
            CHECK_NOTHROW(expressDelivery.deliver(order));
        }
        
        SUBCASE("Total with delivery is correct") {
            double totalWithDelivery = order.total() + expressDelivery.getDeliveryCost();
            CHECK(totalWithDelivery == doctest::Approx(225.0));
        }
    }
    
    TEST_CASE("PickupDelivery - Basic Functionality") {
        Order order;
        OrderItem* item1 = new OrderItem("Lawn Grass", 30.0, 2);
        OrderItem* item2 = new OrderItem("Mint Plant", 20.0, 2);
        order.addItem(item1);
        order.addItem(item2);
        
        PickupDelivery pickupDelivery;
        
        SUBCASE("Order total is correct") {
            CHECK(order.total() == doctest::Approx(100.0));
        }
        
        SUBCASE("Order has correct item count") {
            CHECK(order.getItemCount() == 2);
        }
        
        SUBCASE("PickupDelivery cost is R0 (FREE)") {
            CHECK(pickupDelivery.getDeliveryCost() == doctest::Approx(0.0));
        }
        
        SUBCASE("PickupDelivery type is correct") {
            CHECK(pickupDelivery.getDeliveryType() == "Customer Pickup");
        }
        
        SUBCASE("PickupDelivery delivers without crashing") {
            CHECK_NOTHROW(pickupDelivery.deliver(order));
        }
        
        SUBCASE("Total with delivery is same as order total (FREE)") {
            double totalWithDelivery = order.total() + pickupDelivery.getDeliveryCost();
            CHECK(totalWithDelivery == doctest::Approx(100.0));
        }
    }
    
    TEST_CASE("Strategy Pattern - Polymorphism") {
        Order order;
        OrderItem* item = new OrderItem("Test Plant", 100.0, 1);
        order.addItem(item);
        
        SUBCASE("StandardDelivery through base pointer") {
            DeliveryStrategy* strategy = new StandardDelivery();
            CHECK_NOTHROW(strategy->deliver(order));
            CHECK(strategy->getDeliveryCost() == doctest::Approx(50.0));
            CHECK(strategy->getDeliveryType() == "Standard Delivery");
            delete strategy;
        }
        
        SUBCASE("ExpressDelivery through base pointer") {
            DeliveryStrategy* strategy = new ExpressDelivery();
            CHECK_NOTHROW(strategy->deliver(order));
            CHECK(strategy->getDeliveryCost() == doctest::Approx(150.0));
            CHECK(strategy->getDeliveryType() == "Express Delivery");
            delete strategy;
        }
        
        SUBCASE("PickupDelivery through base pointer") {
            DeliveryStrategy* strategy = new PickupDelivery();
            CHECK_NOTHROW(strategy->deliver(order));
            CHECK(strategy->getDeliveryCost() == doctest::Approx(0.0));
            CHECK(strategy->getDeliveryType() == "Customer Pickup");
            delete strategy;
        }
    }
    
    TEST_CASE("Empty Order Handling") {
        Order emptyOrder;
        
        SUBCASE("Empty order has zero total") {
            CHECK(emptyOrder.total() == doctest::Approx(0.0));
        }
        
        SUBCASE("Empty order has zero items") {
            CHECK(emptyOrder.getItemCount() == 0);
        }
        
        SUBCASE("StandardDelivery handles empty order") {
            StandardDelivery strategy;
            CHECK_NOTHROW(strategy.deliver(emptyOrder));
            CHECK(strategy.getDeliveryCost() == doctest::Approx(50.0));
        }
        
        SUBCASE("ExpressDelivery handles empty order") {
            ExpressDelivery strategy;
            CHECK_NOTHROW(strategy.deliver(emptyOrder));
            CHECK(strategy.getDeliveryCost() == doctest::Approx(150.0));
        }
        
        SUBCASE("PickupDelivery handles empty order") {
            PickupDelivery strategy;
            CHECK_NOTHROW(strategy.deliver(emptyOrder));
            CHECK(strategy.getDeliveryCost() == doctest::Approx(0.0));
        }
    }
    
    TEST_CASE("Delivery Cost Comparison") {
        StandardDelivery standard;
        ExpressDelivery express;
        PickupDelivery pickup;
        
        SUBCASE("Pickup is cheapest (FREE)") {
            CHECK(pickup.getDeliveryCost() < standard.getDeliveryCost());
            CHECK(pickup.getDeliveryCost() < express.getDeliveryCost());
            CHECK(pickup.getDeliveryCost() == doctest::Approx(0.0));
        }
        
        SUBCASE("Standard is cheaper than Express") {
            CHECK(standard.getDeliveryCost() < express.getDeliveryCost());
        }
        
        SUBCASE("Express is most expensive") {
            CHECK(express.getDeliveryCost() > standard.getDeliveryCost());
            CHECK(express.getDeliveryCost() > pickup.getDeliveryCost());
        }
        
        SUBCASE("Express costs 3x Standard") {
            CHECK(express.getDeliveryCost() == doctest::Approx(3.0 * standard.getDeliveryCost()));
        }
    }
    
    TEST_CASE("Large Order Handling") {
        Order largeOrder;
        
        for (int i = 0; i < 10; i++) {
            OrderItem* item = new OrderItem("Plant" + std::to_string(i), 50.0, 5);
            largeOrder.addItem(item);
        }
        
        StandardDelivery standard;
        ExpressDelivery express;
        PickupDelivery pickup;
        
        SUBCASE("Large order total is correct") {
            CHECK(largeOrder.total() == doctest::Approx(2500.0));
        }
        
        SUBCASE("Large order item count is correct") {
            CHECK(largeOrder.getItemCount() == 10);
        }
        
        SUBCASE("All strategies handle large orders") {
            CHECK_NOTHROW(standard.deliver(largeOrder));
            CHECK_NOTHROW(express.deliver(largeOrder));
            CHECK_NOTHROW(pickup.deliver(largeOrder));
        }
        
        SUBCASE("Delivery costs remain constant regardless of order size") {
            CHECK(standard.getDeliveryCost() == doctest::Approx(50.0));
            CHECK(express.getDeliveryCost() == doctest::Approx(150.0));
            CHECK(pickup.getDeliveryCost() == doctest::Approx(0.0));
        }
    }
    
    TEST_CASE("Strategy Pattern - Runtime Strategy Selection") {
        Order order;
        OrderItem* item = new OrderItem("Sample Plant", 75.0, 2);
        order.addItem(item);
        
        SUBCASE("Switch between strategies at runtime") {
            DeliveryStrategy* strategy = nullptr;
            
            strategy = new StandardDelivery();
            CHECK(strategy->getDeliveryType() == "Standard Delivery");
            CHECK_NOTHROW(strategy->deliver(order));
            delete strategy;
            
            strategy = new ExpressDelivery();
            CHECK(strategy->getDeliveryType() == "Express Delivery");
            CHECK_NOTHROW(strategy->deliver(order));
            delete strategy;
            
            strategy = new PickupDelivery();
            CHECK(strategy->getDeliveryType() == "Customer Pickup");
            CHECK_NOTHROW(strategy->deliver(order));
            delete strategy;
        }
    }
    
    TEST_CASE("Order with Single Item") {
        Order order;
        OrderItem* item = new OrderItem("Single Rose", 45.0, 1);
        order.addItem(item);
        
        StandardDelivery standard;
        ExpressDelivery express;
        PickupDelivery pickup;
        
        SUBCASE("Single item order total") {
            CHECK(order.total() == doctest::Approx(45.0));
            CHECK(order.getItemCount() == 1);
        }
        
        SUBCASE("Standard delivery total cost") {
            double total = order.total() + standard.getDeliveryCost();
            CHECK(total == doctest::Approx(95.0));
        }
        
        SUBCASE("Express delivery total cost") {
            double total = order.total() + express.getDeliveryCost();
            CHECK(total == doctest::Approx(195.0));
        }
        
        SUBCASE("Pickup delivery total cost") {
            double total = order.total() + pickup.getDeliveryCost();
            CHECK(total == doctest::Approx(45.0));
        }
    }
    
    TEST_CASE("Multiple Delivery Strategy Instantiation") {
        SUBCASE("Can create multiple strategy instances") {
            StandardDelivery s1, s2, s3;
            ExpressDelivery e1, e2;
            PickupDelivery p1, p2, p3, p4;
            
            CHECK(s1.getDeliveryCost() == s2.getDeliveryCost());
            CHECK(e1.getDeliveryType() == e2.getDeliveryType());
            CHECK(p1.getDeliveryCost() == p4.getDeliveryCost());
        }
    }
    
    TEST_CASE("Order Memory Management") {
        SUBCASE("Order destructor cleans up items") {
            Order* order = new Order();
            OrderItem* item1 = new OrderItem("Plant1", 10.0, 1);
            OrderItem* item2 = new OrderItem("Plant2", 20.0, 1);
            
            order->addItem(item1);
            order->addItem(item2);
            
            CHECK(order->getItemCount() == 2);
            
            CHECK_NOTHROW(delete order);
        }
    }
    
    TEST_CASE("Const Correctness") {
        Order order;
        OrderItem* item = new OrderItem("Test", 50.0, 1);
        order.addItem(item);
        
        const Order& constOrderRef = order;
        
        SUBCASE("Const methods work on const reference") {
            CHECK_NOTHROW(constOrderRef.total());
            CHECK_NOTHROW(constOrderRef.getItemCount());
            CHECK_NOTHROW(constOrderRef.getOrder());
        }
        
        SUBCASE("Delivery strategies accept const Order reference") {
            StandardDelivery standard;
            ExpressDelivery express;
            PickupDelivery pickup;
            
            CHECK_NOTHROW(standard.deliver(constOrderRef));
            CHECK_NOTHROW(express.deliver(constOrderRef));
            CHECK_NOTHROW(pickup.deliver(constOrderRef));
        }
    }
}
