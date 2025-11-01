/**
 * @file StandardDelivery.cpp
 * @brief Implementation of standard delivery strategy
 * @author Zaynab Samir
 */

#include "StandardDelivery.h"
#include "../Order/Order.h"
#include <iostream>

/**
 * @brief Executes standard delivery for an order
 * 
 * Creates a professionally formatted delivery receipt with:
 * - Box-drawing characters (╔═╗║╚╝) for visual borders
 * - Emojis for visual indicators (📦🚚💰🌱⏰📋✅📍)
 * - Detailed pricing breakdown
 * - Item count display
 * - Delivery assurances
 * 
 * The method displays:
 * 1. Header with "STANDARD DELIVERY SERVICE" in a box
 * 2. Delivery method and estimated time
 * 3. Order subtotal from order.total()
 * 4. Delivery fee (R50.00) from getDeliveryCost()
 * 5. Total amount (subtotal + delivery)
 * 6. Number of items from order.getItemCount()
 * 7. Packaging and delivery assurances
 * 8. Footer separator line
 * 
 * @param order Constant reference to the order to be delivered via standard shipping
 * 
 * @note Requires Order class to have:
 *       - total() const method for calculating order subtotal
 *       - getItemCount() const method for getting number of items
 */
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
