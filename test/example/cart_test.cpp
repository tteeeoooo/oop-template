#include <gtest/gtest.h>
#include "cart.h"
#include "drink.h"
#include "noalc.h"
#include "withalc.h"

TEST(CartTest, ProductDeleteTest) {
    // Create a vector of Drink pointers representing the cart contents
    std::vector<Drink*> drinks;
    // Add some drinks to the cart
    // Assuming Drink objects are created elsewhere and added to the vector
    // Create a Cart object with the vector of drinks
    Cart cart(drinks, 50.0, {10.0, 20.0, 30.0});

    // Delete a product from the cart
    cart.productDelete(1);  // Assuming index 1 is the product to be deleted

    // Test if the product was deleted successfully
    // Check if the cart price reflects the deletion of the product
    EXPECT_FLOAT_EQ(cart.cartPrice(), 30.0);
}
