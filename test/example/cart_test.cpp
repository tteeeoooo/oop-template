#include <gtest/gtest.h>
#include "cart.h"
#include "drink.h"
#include "noalc.h"
#include "withalc.h"

TEST(CartTest, GiveATipTest) {
    // Create some Drink objects for the cart
    Drink* drink1 = new Drink("Coffee", 2.5);
    Drink* drink2 = new Drink("Tea", 3.0);
    std::vector<Drink*> drinks = {drink1, drink2};

    // Create a Cart object with the drinks
    Cart cart(drinks, 5.5, {2.5, 3.0});

    // Test the giveATip function
    // Check if the function calculates the tip correctly
    // For simplicity, we assume the user input is provided as expected
    cart.giveATip(cart);
    // Check if the cart price reflects the addition of the tip
    EXPECT_FLOAT_EQ(cart.cartPrice(), 8.25);  // Assuming a 50% tip on a cart with price 5.5
}
