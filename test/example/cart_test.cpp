#include <gtest/gtest.h>
#include "cart.h"

int mockInput(const std::string& input) {
    std::istringstream iss(input);
    std::cin.rdbuf(iss.rdbuf());
    int value;
    std::cin >> value;
    return value;
}

TEST(CartTest, GiveATipTest) {
    // Se creează un meniu de băuturi de test
    std::vector<Drink*> coffeeMenu = {new NoAlc("TestDrink1", 5.0), new NoAlc("TestDrink2", 7.0)};
    Cart cart({}, 10.0, {});

    // Simularea introducerii de la tastatură: se introduce 2 pentru a reprezenta 20% pentru bacșiș
    int userInput = mockInput("2\n");

    // Verificarea că se calculează corect procentul pentru bacșiș
    testing::internal::CaptureStdout();
    cart.giveATip(cart);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You will have to pay: 12\n");

    // Se eliberează memoria pentru băuturi
    for (auto drink : coffeeMenu) {
        delete drink;
    }
}
