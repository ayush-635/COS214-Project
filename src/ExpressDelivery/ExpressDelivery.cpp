/**
 * @file ExpressDelivery.cpp
 * @brief Implementation of express delivery strategy
 * @author Zaynab Samir
 */

#include "ExpressDelivery.h"
#include "../Order/Order.h"
#include <iostream>

/**
 * @brief Executes express delivery for an order
 * 
 * Creates a premium-styled delivery receipt with:
 * - Box-drawing characters (╔═╗║╚╝) for visual borders
 * - Lightning bolt emojis (⚡) to emphasize speed
 * - Various emojis for visual indicators (🚀🌱🚚💰📋⭐📦📱🎁)
 * - Detailed pricing breakdown
 * - Item count display
 * - Premium service features
 * 
 * The method displays:
 * 1. Header with "⚡ EXPRESS DELIVERY SERVICE ⚡" in a box
 * 2. Delivery method (Express Shipping) with rocket emoji 🚀
 * 3. Fast estimated delivery time (1-2 business days) with lightning ⚡
 * 4. Order subtotal from order.total()
 * 5. Express delivery fee (R150.00) from getDeliveryCost()
 * 6. Total amount (subtotal + delivery)
 * 7. Number of items from order.getItemCount()
 * 8. Priority package notification with star ⭐
 * 9. Same-day dispatch eligibility (orders before 2 PM)
 * 10. Real-time tracking availability with phone emoji 📱
 * 11. Premium packaging notice with gift box 🎁
 * 12. Footer separator line
 * 
 * @param order Constant reference to the order to be delivered via express shipping
 * 
 * @note Requires Order class to have:
 *       - total() const method for calculating order subtotal
 *       - getItemCount() const method for getting number of items
 * 
 * @note Express delivery costs R150.00 (3x standard delivery) but provides
 *       significantly faster service with additional premium features
 */
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
