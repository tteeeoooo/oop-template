#include <gtest/gtest.h>
#include "noalc.h"

TEST(NoAlcTest, AssignmentOperatorTest) {
    NoAlc drink1("Soda", 2.5, 100);
    NoAlc drink2("Cola", 3.0, 150);
    drink1 = drink2;
    EXPECT_EQ(drink1.getDrinkChoice(), "Cola");
    EXPECT_DOUBLE_EQ(drink1.getPrice(), 3.0);
    EXPECT_EQ(drink1.getCalories(), 150);
}
