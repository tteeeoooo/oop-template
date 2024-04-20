#include <gtest/gtest.h>
#include "noalc.h"

// Testăm funcția getCalories()
TEST(SuiteName, TestName) {
    // Cream un obiect de tip NoAlc cu anumite valori
    NoAlc drink("Soda", 2.5, 100);

    // Verificăm dacă funcția getCalories() returnează valoarea corectă
    EXPECT_EQ(drink.getCalories(), 100);
}
