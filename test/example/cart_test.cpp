#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, GiveATipTest) {
    // Se creează un meniu de băuturi de test
    std::vector<Drink*> coffeeMenu = {new NoAlc("TestDrink1", 5.0), new NoAlc("TestDrink2", 7.0)};
    Cart cart({}, 10.0, {});

    // Se verifică că se calculează corect procentul pentru bacșiș
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    std::istringstream input("2"); // Se introduce 20% pentru bacșiș
    std::cin.rdbuf(input.rdbuf());
    cart.giveATip(cart);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You will have to pay: 12\n");

    // Se eliberează memoria pentru băuturi
    for (auto drink : coffeeMenu) {
        delete drink;
    }
}
