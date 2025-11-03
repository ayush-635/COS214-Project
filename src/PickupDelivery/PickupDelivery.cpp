#include "PickupDelivery.h"
#include "../Order/Order.h"
#include <iostream>

void PickupDelivery::deliver(const Order& order) {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║       🏪 CUSTOMER PICKUP SERVICE       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::cout << "\n🚶 Delivery Method: Customer Pickup" << std::endl;
    std::cout << "📍 Pickup Location: Main Nursery - 123 Garden St" << std::endl;
    std::cout << "🌱 Order Subtotal: R" << order.total() << std::endl;
    std::cout << "🚚 Delivery Fee: R" << getDeliveryCost() << " (FREE PICKUP!)" << std::endl;
    std::cout << "💰 Total Amount: R" << (order.total() + getDeliveryCost()) << std::endl;
    std::cout << "\n📋 " << order.getItemCount() << " item(s) ready for pickup" << std::endl;
    std::cout << "⏰ Order ready in 2-4 hours" << std::endl;
    std::cout << "🆔 Please bring ID and order confirmation" << std::endl;
    std::cout << "🕐 Pickup Hours:" << std::endl;
    std::cout << "   Mon-Sat: 8AM-6PM" << std::endl;
    std::cout << "   Sunday: 9AM-4PM" << std::endl;
    std::cout << "════════════════════════════════════════" << std::endl;
}