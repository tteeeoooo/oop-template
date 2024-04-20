#include <gtest/gtest.h>
#include "noalc.h"

TEST(NoAlcTest, Constructor) {
    NoAlc drink("Orange Juice", 2.5, 120);
    EXPECT_EQ(drink.getDrinkName(), "Orange Juice");
    EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 2.5);
    EXPECT_EQ(drink.getCalories(), 120);
}

TEST(NoAlcTest, Description) {
    NoAlc drink("Water", 1.0, 0);
    testing::internal::CaptureStdout(); 
    drink.description();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("This drink contains 0 calories!"), std::string::npos);
}

TEST(NoAlcTest, PriceModifier) {
    NoAlc drink("Soda", 2.0, 150);
    EXPECT_DOUBLE_EQ(drink.priceModifier(), 2.38); 
}

TEST(NoAlcTest, AssignmentOperator) {
    NoAlc drink1("Apple Juice", 3.0, 100);
    NoAlc drink2;
    drink2 = drink1;
    EXPECT_EQ(drink2.getDrinkName(), "Apple Juice");
    EXPECT_DOUBLE_EQ(drink2.getDrinkPrice(), 3.0);
    EXPECT_EQ(drink2.getCalories(), 100);
}

TEST(NoAlcTest, OutputOperator) {
    NoAlc drink("Tea", 1.5, 50);
    testing::internal::CaptureStdout(); 
    std::cout << drink; // Folosim operatorul de afișare
    std::string output = testing::internal::GetCapturedStdout(); 
    EXPECT_NE(output.find("Tea 1.5 50"), std::string::npos);
}
