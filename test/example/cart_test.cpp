#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, CreditCardInfoTest) {
    // Create a cart with some drinks
    std::vector<Drink*> drinks;
    drinks.push_back(new Drink("Coffee", 2.5));
    drinks.push_back(new Drink("Tea", 3.0));
    Cart cart(drinks, 5.5, {2.5, 3.0});

    // Redirect cin to stringstream for testing user input
    std::stringstream ss("1234567890\n123\n0\n");
    std::streambuf* oldCin = std::cin.rdbuf(ss.rdbuf());
    cart.creditCardInfo(cart);
    std::cin.rdbuf(oldCin); // Reset cin redirection

    // Check if the tip calculation is correct
    EXPECT_FLOAT_EQ(cart.cartPrice(), 5.5);
}
