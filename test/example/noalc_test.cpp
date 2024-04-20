#include <gtest/gtest.h>
#include "noalc.h"

TEST(NoAlcTest, GetCaloriesTest) {
    NoAlc drinkity("Espresso", 2.5, 100);

    EXPECT_EQ(drinkity.getCalories(), 100);
}
