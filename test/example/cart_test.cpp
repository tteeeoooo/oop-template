#include "cart.h" 
#include <gtest/gtest.h> 
TEST(CartTest, ConstructorTest) {
    Cart cart;
    EXPECT_EQ(cart.cartPrice(), 0);
}

TEST(CartTest, CopyConstructorTest) {
    Cart original;
    Cart copy(original);
    EXPECT_EQ(copy.cartPrice(), 0);
}

TEST(CartTest, ProductDeleteTest) {
    Cart cart;
    cart.productDelete(0); // Testăm eliminarea unui produs dintr-un coș gol
    EXPECT_EQ(cart.cartPrice(), 0);
}

TEST(CartTest, CartPriceTest) {
    Cart cart;
    EXPECT_EQ(cart.cartPrice(), 0);
}

TEST(CartTest, GetDrinksTest) {
    Cart cart;
    std::vector<Drink*> drinks = cart.getDrinks(cart);
    EXPECT_TRUE(drinks.empty()); 
}

TEST(CartTest, AssignmentOperatorTest) {
    Cart original;
    Cart copy;
    copy = original;
    EXPECT_EQ(copy.cartPrice(), 0);
}

TEST(CartTest, OutputOperatorTest) {
    Cart cart;
    std::stringstream ss;
    ss << cart;
    std::string output = ss.str();
    EXPECT_NE(output.find("Your shopping cart status:"), std::string::npos);
}

TEST(CartTest, AtAddressPaymentTest) {
    Cart cart;
}

TEST(CartTest, CreditCardInfoTest) {
    Cart cart;
}

TEST(CartTest, OrderTest) {
    Cart cart;
    std::vector<Drink*> coffeeMenu;
}

TEST(CartTest, ReadyToOrderTest) {
    Cart cart;
    std::vector<Drink*> coffeeMenu;
}

TEST(CartTest, DeliveryAddressTest) {
    Cart cart;
}

TEST(CartTest, GiveATipTest) {
    Cart cart;
}

TEST(CartTest, EverythingTest) {
    Cart cart;
    std::vector<Drink*> coffeeMenu;
}
