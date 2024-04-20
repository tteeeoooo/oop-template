#include <gtest/gtest.h>
#include "drink.h"
#include "noalc.h"

TEST(NoAlcTest, PriceModifierTest) {
    NoAlc drinkity("Soda", 2.5, 100);
    EXPECT_DOUBLE_EQ(drinkity.priceModifier(), 2.975);
}

TEST(NoAlcTest, DescriptionTest) {
    NoAlc drink("Mocktail", 5.0, 50);
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf(ss.rdbuf()); // Redirect cout to stringstream
    drink.description();
    std::cout.rdbuf(oldCout); // Reset cout redirection
    EXPECT_EQ(ss.str(), "This drink contains 50 calories!\n");
}
