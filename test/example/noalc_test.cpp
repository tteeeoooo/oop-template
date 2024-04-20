#include <gtest/gtest.h>
#include "drink.h"
#include "noalc.h"

TEST(NoAlcTest, PriceModifierTest) {
    NoAlc drinkity("Soda", 2.5, 100);
    EXPECT_DOUBLE_EQ(drinkity.priceModifier(), 2.975);
}
