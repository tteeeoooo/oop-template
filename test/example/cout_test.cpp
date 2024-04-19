#include "cout.h" 
#include <gtest/gtest.h>

TEST(CoutTest, MenuTextTest) {
    std::stringstream ss;
    std::streambuf* prevOut = std::cout.rdbuf(ss.rdbuf());

    Cout::menuText();

    std::string output = ss.str();
    EXPECT_TRUE(output.find("Menu Text") != std::string::npos); 

    std::cout.rdbuf(prevOut);
}

TEST(CoutTest, PriceCalculationTest) {
    float oldPrice = 100.0f;
    float sale = 20.0f;
    float newPrice = Cout::priceCalculation(oldPrice, sale);
    EXPECT_FLOAT_EQ(newPrice, 80.0f);
}

TEST(CoutTest, UnderLineTest) {}
