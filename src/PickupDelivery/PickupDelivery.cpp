/**
 * @file PickupDelivery.cpp
 * @brief Implementation of customer pickup delivery strategy
 * @author Zaynab Samir
 */

#include "PickupDelivery.h"
#include "../Order/Order.h"
#include <iostream>

/**
 * @brief Processes order for customer pickup
 * 
 * Creates a customer-friendly pickup information receipt with:
 * - Box-drawing characters (╔═╗║╚╝) for visual borders
 * - Store emoji (🏪) in header to indicate physical location
 * - Various emojis for visual indicators (🚶📍🌱🚚💰📋⏰🆔🕐)
 * - Detailed location and timing information
 * - Required documentation reminders
 * 
 * The method displays:
 * 1. Header with "🏪 CUSTOMER PICKUP SERVICE" in a box
 * 2. Delivery method (Customer Pickup) with walking person emoji 🚶
 * 3. Physical pickup location address (Main Nursery - 123 Garden St)
 * 4. Order subtotal from order.total()
 * 5. Delivery fee (R0.00 - FREE PICKUP!) from getDeliveryCost()
 * 6. Total amount (same as subtotal - no additional charges)
 * 7. Number of items from order.getItemCount()
 * 8. Order preparation time (2-4 hours) with clock emoji ⏰
 * 9. Required documents reminder (ID and order confirmation) with ID emoji 🆔
 * 10. Detailed pickup hours schedule with clock emoji 🕐:
 *     - Monday-Saturday: 8AM-6PM
 *     - Sunday: 9AM-4PM
 * 11. Footer separator line
 * 
 * @param order Constant reference to the order to be prepared for customer pickup
 * 
 * @note Requires Order class to have:
 *       - total() const method for calculating order subtotal
 *       - getItemCount() const method for getting number of items
 * 
 * @note Customer Pickup is FREE (R0.00) making it the most economical option,
 *       but requires customers to travel to Main Nursery location
 * 
 * @note Customers must bring:
 *       - Valid ID (identification document)
 *       - Order confirmation (receipt or order number)
 */
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
