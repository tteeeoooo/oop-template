#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, ProductDeleteTest) {
    // Create a cart with some drinks
    std::vector<Drink*> drinks;
    drinks.push_back(new Drink("Coffee", 2.5));
    drinks.push_back(new Drink("Tea", 3.0));
    Cart cart(drinks, 5.5, {2.5, 3.0});

    // Delete a product from the cart
    cart.productDelete(1);

    // Check if the price and number of drinks are updated correctly
    EXPECT_FLOAT_EQ(cart.cartPrice(), 3.0);
    EXPECT_EQ(cart.getDrinks(cart).size(), 1);
}
