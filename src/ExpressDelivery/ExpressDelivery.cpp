#include "ExpressDelivery.h"
#include "../Order/Order.h"
#include <iostream>

void ExpressDelivery::deliver(const Order& order) {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║    ⚡ EXPRESS DELIVERY SERVICE ⚡      ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::cout << "\n🚀 Delivery Method: Express Shipping" << std::endl;
    std::cout << "⚡ Estimated Delivery: 1-2 business days" << std::endl;
    std::cout << "🌱 Order Subtotal: R" << order.total() << std::endl;
    std::cout << "🚚 Express Fee: R" << getDeliveryCost() << std::endl;
    std::cout << "💰 Total Amount: R" << (order.total() + getDeliveryCost()) << std::endl;
    std::cout << "\n📋 " << order.getItemCount() << " item(s) in this order" << std::endl;
    std::cout << "⭐ PRIORITY PACKAGE - Expedited Processing" << std::endl;
    std::cout << "📦 Same-day dispatch if ordered before 2 PM" << std::endl;
    std::cout << "📱 Real-time tracking available" << std::endl;
    std::cout << "🎁 Premium packaging included" << std::endl;
    std::cout << "════════════════════════════════════════" << std::endl;
}