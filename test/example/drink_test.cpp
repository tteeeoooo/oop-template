#include "Drink.h"
#include <gtest/gtest.h>

TEST(DrinkTest, ConstructorTest) {
    Drink drink("Cappuccino", 3.5);
    EXPECT_EQ(drink.getDrinkName(), "Cappuccino");
    EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 3.5);
}

TEST(DrinkTest, CopyConstructorTest) {
    Drink original("Latte", 4.0);
    Drink copy(original);
    EXPECT_EQ(copy.getDrinkName(), "Latte");
    EXPECT_DOUBLE_EQ(copy.getDrinkPrice(), 4.0);
}

TEST(DrinkTest, AssignmentOperatorTest) {
    Drink original("Espresso", 2.5);
    Drink copy;
    copy = original;
    EXPECT_EQ(copy.getDrinkName(), "Espresso");
    EXPECT_DOUBLE_EQ(copy.getDrinkPrice(), 2.5);
}

TEST(DrinkTest, DescriptionTest) {
    EXPECT_EQ(drink.description(), "Descrierea așteptată");
}

TEST(DrinkTest, PriceModifierTest) {
    EXPECT_DOUBLE_EQ(drink.priceModifier(), 3.0);
}

TEST(DrinkTest, DestructorTest) {
    ASSERT_NO_THROW(delete drink);
}
