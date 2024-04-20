#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, GiveATipTest) {
    // Se creează un obiect Cart și se setează un preț de 10.0
    Cart cart({}, 10.0, {});

    // Se calculează valoarea totală de plată pentru un bacșiș de 20%
    float totalAmount = cart.giveATip(20);

    // Se verifică că valoarea totală de plată este corectă (12.0)
    EXPECT_FLOAT_EQ(totalAmount, 12.0);
}
