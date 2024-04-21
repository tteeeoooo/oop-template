#include <gtest/gtest.h>
#include "drink.h" // Presupunând că aici este inclus fișierul header pentru clasa Drink

TEST(DrinkTest, MenuOptions) {
    std::vector<Drink*> coffeeMenu;

    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    Drink::menuOptions(coffeeMenu);

    std::cout.rdbuf(oldCout);
}

