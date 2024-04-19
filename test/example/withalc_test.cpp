#include "withalc.h" 
#include <gtest/gtest.h>

TEST(WithAlcTest, ConstructorTest) {
    WithAlc drink("Beer", 3.0, 5);
    EXPECT_EQ(drink.getDrinkName(), "Beer");
    EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 3.0);
    EXPECT_EQ(drink.getAlc(), 5);
}

TEST(WithAlcTest, CopyConstructorTest) {
    WithAlc original("Wine", 5.0, 10);
    WithAlc copy(original);
    EXPECT_EQ(copy.getDrinkName(), "Wine");
    EXPECT_DOUBLE_EQ(copy.getDrinkPrice(), 5.0);
    EXPECT_EQ(copy.getAlc(), 10);
}

TEST(WithAlcTest, DescriptionTest) {
    EXPECT_EQ(drink.description(), "Descrierea așteptată");
}

TEST(WithAlcTest, PriceModifierTest) {
    EXPECT_DOUBLE_EQ(drink.priceModifier(), 3.0);
}

TEST(WithAlcTest, AgeCheckTest) {
}

TEST(WithAlcTest, OutputOperatorTest) {
    WithAlc drink("Whiskey", 8.0, 40);
    std::stringstream ss;
    ss << drink;
    std::string output = ss.str();
    EXPECT_NE(output.find("Whiskey"), std::string::npos);
    EXPECT_NE(output.find("8.0"), std::string::npos);
    EXPECT_NE(output.find("40"), std::string::npos);
}

TEST(WithAlcTest, InputOperatorTest) {
    WithAlc drink;
    std::stringstream ss("Vodka\n6.0\n50\n");
    ss >> drink;
    EXPECT_EQ(drink.getDrinkName(), "Vodka");
    EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 6.0);
    EXPECT_EQ(drink.getAlc(), 50);
}

TEST(WithAlcTest, AssignmentOperatorTest) {
    WithAlc original("Rum", 7.0, 30);
    WithAlc copy;
    copy = original;
    EXPECT_EQ(copy.getDrinkName(), "Rum");
    EXPECT_DOUBLE_EQ(copy.getDrinkPrice(), 7.0);
    EXPECT_EQ(copy.getAlc(), 30);
}

TEST(WithAlcTest, DestructorTest) {
    ASSERT_NO_THROW(delete drink);
}
