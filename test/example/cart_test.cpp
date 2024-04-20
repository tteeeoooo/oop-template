#include <gtest/gtest.h>
#include "cart.h"
// #include "drink.h"
// #include "noalc.h"
// #include "withalc.h"

TEST(CartTest, CartPriceEmptyTest) {
    // Create an empty cart
    Cart cart({}, 0, {});

    // Test the cartPrice function
    EXPECT_FLOAT_EQ(cart.cartPrice(), 0);
}
