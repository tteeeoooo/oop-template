#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, GiveATipTest) {
    // Se creează un obiect Cart și se setează un preț de 10.0
    Cart cart({}, 10.0, {});

    // Se calculează valoarea bacșișului pentru 20%
    float tipAmount = cart.calculateTip(20);

    // Se verifică că valoarea calculată este corectă (2.0)
    EXPECT_FLOAT_EQ(tipAmount, 2.0);
}
