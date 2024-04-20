#include <gtest/gtest.h>
#include "cart.h"
#include "drink.h"
#include "noalc.h"
#include "withalc.h"

TEST(CartTest, CartPriceTest) {
    // Create some Drink objects for the cart
    Drink* drink1 = new Drink("Coffee", 2.5);
    Drink* drink2 = new Drink("Tea", 3.0);
    std::vector<Drink*> drinks = {drink1, drink2};

    // Create a Cart object with the drinks
    Cart cart(drinks, 5.5, {2.5, 3.0});

    // Test the cartPrice function
    EXPECT_FLOAT_EQ(cart.cartPrice(), 5.5);
}
