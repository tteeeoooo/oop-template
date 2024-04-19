#include "noalc.h" 
#include <gtest/gtest.h>
#include <sstream>

TEST(NoAlcTest, ConstructorTest) {
    NoAlc drink("Fruit Juice", 2.0, 100);
    EXPECT_EQ(drink.getDrinkName(), "Fruit Juice");
    EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 2.0);
    EXPECT_EQ(drink.getCalories(), 100);
}

TEST(NoAlcTest, CopyConstructorTest) {
    NoAlc original("Lemonade", 1.5, 50);
    NoAlc copy(original);
    EXPECT_EQ(copy.getDrinkName(), "Lemonade");
    EXPECT_DOUBLE_EQ(copy.getDrinkPrice(), 1.5);
    EXPECT_EQ(copy.getCalories(), 50);
}

TEST(NoAlcTest, DescriptionTest) {
    EXPECT_EQ(drink.description(), "Descrierea așteptată");
}

TEST(NoAlcTest, PriceModifierTest) {
    EXPECT_DOUBLE_EQ(drink.priceModifier(), 2.0);
}

TEST(NoAlcTest, OutputOperatorTest) {
    NoAlc drink("Iced Tea", 2.5, 60);
    std::stringstream ss;
    ss << drink;
    std::string output = ss.str();
    EXPECT_NE(output.find("Iced Tea"), std::string::npos);
    EXPECT_NE(output.find("2.5"), std::string::npos);
    EXPECT_NE(output.find("60"), std::string::npos);
}

TEST(NoAlcTest, InputOperatorTest) {
    NoAlc drink;
    std::stringstream ss("Water\n1.0\n0\n");
    ss >> drink;
    EXPECT_EQ(drink.getDrinkName(), "Water");
    EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 1.0);
    EXPECT_EQ(drink.getCalories(), 0);
}

TEST(NoAlcTest, AssignmentOperatorTest) {
    NoAlc original("Fruit Punch", 2.0, 120);
    NoAlc copy;
    copy = original;
    EXPECT_EQ(copy.getDrinkName(), "Fruit Punch");
    EXPECT_DOUBLE_EQ(copy.getDrinkPrice(), 2.0);
    EXPECT_EQ(copy.getCalories(), 120);
}

TEST(NoAlcTest, DestructorTest) {
    ASSERT_NO_THROW(delete drink);
}
