#include <gtest/gtest.h>
#include "noalc.h"

// Testăm funcția getCalories()
TEST(SuiteName, TestName) {
    NoAlc drinkity("Espresso", 2.5, 100);

    // Verificăm dacă funcția getCalories() returnează valoarea corectă
    EXPECT_EQ(drinkity.getCalories(), 100);
}
