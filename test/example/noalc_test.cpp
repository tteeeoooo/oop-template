#include <gtest/gtest.h>
#include "noalc.h"

TEST(NoAlcTest, PriceModifierTest) {
    // Cream un obiect de tip NoAlc cu anumite valori
    NoAlc drink("Coffee", 3.0, 120);

    // Verificăm dacă funcția priceModifier() calculează prețul corect
    EXPECT_DOUBLE_EQ(drink.priceModifier(), 3.57);
}
