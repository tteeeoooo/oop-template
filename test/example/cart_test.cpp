#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, GiveATipTest) {
    // Se creează un meniu de băuturi de test
    std::vector<Drink*> coffeeMenu = {new NoAlc("TestDrink1", 5.0), new NoAlc("TestDrink2", 7.0)};
    Cart cart({}, 10.0, {});

    // Simularea introducerii de la tastatură: se introduce 2 pentru a reprezenta 20% pentru bacșiș
    int userInput = 2;

    // Se apelează funcția giveATip și se verifică rezultatul
    testing::internal::CaptureStdout();
    cart.giveATip(cart);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You will have to pay: 12\n");

    // Se eliberează memoria pentru băuturi
    for (auto drink : coffeeMenu) {
        delete drink;
    }
}
