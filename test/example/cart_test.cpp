#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, GiveATipTest) {
    // Se creează un meniu de băuturi de test
    std::vector<Drink*> coffeeMenu = {new NoAlc("TestDrink1", 5.0), new NoAlc("TestDrink2", 7.0)};
    Cart cart({}, 10.0, {});

    // Se apelează funcția giveATip și se obține valoarea bacșișului pentru 20%
    float tipAmount = cart.calculateTip(20);

    // Se verifică că valoarea bacșișului este corect calculată
    EXPECT_EQ(tipAmount, 2.0);

    // Se eliberează memoria pentru băuturi
    for (auto drink : coffeeMenu) {
        delete drink;
    }
}
