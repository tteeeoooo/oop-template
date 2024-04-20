#include <gtest/gtest.h>
#include "withalc.h"

TEST(WithAlcTest, Constructor) {
    WithAlc drink("Whiskey", 10.0, 40);
    EXPECT_EQ(drink.getDrinkName(), "Whiskey");
    EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 10.0);
    EXPECT_EQ(drink.getAlc(), 40);
}

TEST(WithAlcTest, Description) {
    WithAlc drink("Vodka", 5.0, 35);
    testing::internal::CaptureStdout();
    drink.description();
    std::string output = testing::internal::GetCapturedStdout(); 
    EXPECT_NE(output.find("This drink contains alcohol in a percentage of 35%"), std::string::npos);
}

TEST(WithAlcTest, PriceModifier) {
    WithAlc drink("Rum", 8.0, 25);
    EXPECT_DOUBLE_EQ(drink.priceModifier(), 9.88); // Pretul cu 19% TVA și acciză adăugate
}

TEST(WithAlcTest, AgeCheck) {
    EXPECT_TRUE(WithAlc::ageCheck());
}

TEST(WithAlcTest, AssignmentOperator) {
    WithAlc drink1("Gin", 6.0, 30);
    WithAlc drink2;
    drink2 = drink1;
    EXPECT_EQ(drink2.getDrinkName(), "Gin");
    EXPECT_DOUBLE_EQ(drink2.getDrinkPrice(), 6.0);
    EXPECT_EQ(drink2.getAlc(), 30);
}

TEST(WithAlcTest, OutputOperator) {
    WithAlc drink("Beer", 3.5, 5);
    testing::internal::CaptureStdout(); 
    std::cout << drink; 
    std::string output = testing::internal::GetCapturedStdout(); 
    EXPECT_NE(output.find("Beer 3.5 5"), std::string::npos);
}
