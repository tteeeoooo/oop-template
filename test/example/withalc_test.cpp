#include <gtest/gtest.h>
#include "drink.h"
#include "withalc.h"

TEST(WithAlcTest, PriceModifierTest) {
    WithAlc drink("Beer", 3.0, 5);
    EXPECT_DOUBLE_EQ(drink.priceModifier(), 3.564); // Calculul a fost verificat manual
}
