#include <gtest/gtest.h>
#include "cart.h"
#include "drink.h"
#include "noalc.h"
#include "withalc.h"

TEST(CartTest, CartPriceTest) {
    // Create a vector of Drink pointers representing the cart contents
    std::vector<Drink*> drinks;
    // Add some drinks to the cart
    // Assuming Drink objects are created elsewhere and added to the vector
    // Create a Cart object with the vector of drinks
    Cart cart(drinks, 50.0, {10.0, 20.0, 30.0});

    // Test the cartPrice function
    // Check if the expected cart price matches the actual cart price
    EXPECT_FLOAT_EQ(cart.cartPrice(), 50.0);
}
