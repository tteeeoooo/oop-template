#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, CartPriceTest) {
    // Create a cart with some drinks
    std::vector<Drink*> drinks;
    drinks.push_back(new Drink("Coffee", 2.5));
    drinks.push_back(new Drink("Tea", 3.0));
    Cart cart(drinks, 5.5, {2.5, 3.0});

    // Check if the cart price is calculated correctly
    EXPECT_FLOAT_EQ(cart.cartPrice(), 5.5);
}

