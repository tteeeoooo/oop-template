#include <gtest/gtest.h>
#include "cart.h"
#include "drink.h"
#include "noalc.h"
#include "withalc.h"

TEST(CartTest, GiveATipTest) {
    // Se setează un preț de 10.0 și un procent de bacșiș de 20%
    float cartPrice = 10.0;
    int tipPercentage = 20;

    // Se creează un obiect Cart și se calculează valoarea totală de plată, inclusiv bacșișul
    Cart cart({}, cartPrice, {});
    float totalAmount = cart.giveATip(cartPrice, tipPercentage);

    // Se verifică că valoarea totală de plată este corectă (12.0)
    EXPECT_FLOAT_EQ(totalAmount, 12.0);
}
