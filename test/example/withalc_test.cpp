#include <gtest/gtest.h>
#include "drink.h"
#include "withalc.h"

TEST(WithAlcTest, PriceModifierTest) {
    WithAlc drink("Beer", 3.0, 5);
    
    double modifiedPrice = drink.priceModifier();
    
    double expectedPrice = 3.0 + (3.0 * 19 / 100) + ((3.0 + (3.0 * 19 / 100)) * 5 / 100);
    
    EXPECT_DOUBLE_EQ(modifiedPrice, expectedPrice);
}

TEST(WithAlcTest, AgeCheckTest) {
    WithAlc drink("Whiskey", 10.0, 12);
    
    std::istringstream iss("20");
    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    std::streambuf* oldCin = std::cin.rdbuf(iss.rdbuf());
    
    EXPECT_FALSE(drink.ageCheck());
    
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

TEST(WithAlcTest, DescriptionTest) {
    WithAlc drink("Wine", 10.0, 12);
    
    testing::internal::CaptureStdout();
    
    drink.description();
    
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("This drink contains alcohol in a percentage of"), std::string::npos);
}




