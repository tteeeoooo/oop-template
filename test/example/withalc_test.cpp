#include <gtest/gtest.h>
#include "drink.h"
#include "withalc.h"

TEST(NoAlcTest, PriceModifierTest) {
    NoAlc drinkity("Wine", 25, 9);
    EXPECT_DOUBLE_EQ(drinkity.priceModifier(), 31.2375);
}
