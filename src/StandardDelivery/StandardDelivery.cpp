#include "StandardDelivery.h"
#include "../Order/Order.h"
#include <iostream>

void StandardDelivery::deliver(const Order& order) {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║       STANDARD DELIVERY SERVICE        ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::cout << "\n📦 Delivery Method: Standard Shipping" << std::endl;
    std::cout << "⏰ Estimated Delivery: 3-5 business days" << std::endl;
    std::cout << "🌱 Order Subtotal: R" << order.total() << std::endl;
    std::cout << "🚚 Delivery Fee: R" << getDeliveryCost() << std::endl;
    std::cout << "💰 Total Amount: R" << (order.total() + getDeliveryCost()) << std::endl;
    std::cout << "\n📋 " << order.getItemCount() << " item(s) in this order" << std::endl;
    std::cout << "✅ Your plants will be carefully packaged" << std::endl;
    std::cout << "📍 Delivery to your doorstep" << std::endl;
    std::cout << "════════════════════════════════════════" << std::endl;
}