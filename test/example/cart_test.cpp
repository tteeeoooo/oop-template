#include <gtest/gtest.h>
#include "cart.h"

// Funcția giveATip este izolată și poate fi testată separat
float giveATip(float cartPrice, int tipPercentage) {
    float tipAmount = cartPrice * (tipPercentage / 100.0f);
    return cartPrice + tipAmount;
}

TEST(CartTest, GiveATipTest) {
    // Se setează un preț de 10.0 și un procent de bacșiș de 20%
    float cartPrice = 10.0;
    int tipPercentage = 20;

    // Se calculează valoarea totală de plată, inclusiv bacșișul
    float totalAmount = giveATip(cartPrice, tipPercentage);

    // Se verifică că valoarea totală de plată este corectă (12.0)
    EXPECT_FLOAT_EQ(totalAmount, 12.0);
}
