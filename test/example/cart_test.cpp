#include "cart.h" 
#include <gtest/gtest.h>
#include <vector>

TEST(CartTest, DefaultConstructor) {
    Cart cart;
    EXPECT_EQ(cart.cartPrice(), 0.0f); 
    EXPECT_TRUE(cart.getDrinks(cart).empty()); 
}

TEST(CartTest, ParameterizedConstructor) {
    std::vector<Drink*> drinks = {};
    std::vector<float> prices = {};
    Cart cart(drinks, 50.0f, prices);
    EXPECT_EQ(cart.cartPrice(), 50.0f);
    EXPECT_EQ(cart.getDrinks(cart).size(), drinks.size()); 
}

TEST(CartTest, ProductDeleteTest) {
    Cart cart;
}

TEST(CartTest, CartPriceTest) {
    Cart cart;
}
