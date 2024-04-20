#include <gtest/gtest.h>
#include "cart.h"
#include "drink.h"
#include "noalc.h"
#include "withalc.h"

TEST(CartTest, OrderTest) {
    // Create a vector of Drink pointers representing the coffee menu
    std::vector<Drink*> coffeeMenu;
    // Add some drinks to the coffee menu
    // Assuming Drink objects are created elsewhere and added to the vector
    // Create an empty vector of Drink pointers representing the cart contents
    std::vector<Drink*> drinks;
    // Create a Cart object with the empty vector of drinks
    Cart cart(drinks, 0.0, {});

    // Test the order function
    // For simplicity, we assume the order function executes without errors
    // This test can be extended with more specific scenarios
    cart.order(cart, coffeeMenu);
}
