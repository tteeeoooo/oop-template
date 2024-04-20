#include <gtest/gtest.h>
#include "drink.h" // Presupunând că aici este inclus fișierul header pentru clasa Drink

TEST(DrinkTest, MenuOptions) {
    // Testăm funcția menuOptions() din clasa Drink

    // Inițializăm vectorul de băuturi pentru meniu
    std::vector<Drink*> coffeeMenu;

    // Adăugăm câteva băuturi în meniu (presupunem că sunt inițializate corect)
    // coffeeMenu.push_back(/* Obiect de tip Drink */);
    // coffeeMenu.push_back(/* Obiect de tip Drink */);
    // coffeeMenu.push_back(/* Obiect de tip Drink */);

    // Redirecționăm ieșirea standard (cout) către un stringstream pentru a putea verifica mesajele afișate
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Apelăm funcția menuOptions() pentru a afișa meniul
    Drink::menuOptions(coffeeMenu);

    // Verificăm dacă mesajele afișate sunt corecte
    // Aici adăugați aserțiuni pentru a verifica mesajele afișate în funcția menuOptions()

    // Resetăm ieșirea standard la valoarea anterioară
    std::cout.rdbuf(oldCout);
}

TEST(DrinkTest, SameDrinkEqualTest) {
    // Create two drinks with the same name and price
    Drink drink1("Latte", 3.5);
    Drink drink2("Latte", 3.5);
    
    // Check if both drinks are equal
    EXPECT_EQ(drink1, drink2);
}

TEST(DrinkTest, DifferentDrinksNotEqualTest) {
    // Create two drinks with different names and prices
    Drink drink1("Latte", 3.5);
    Drink drink2("Mocha", 4.0);
    
    // Check if both drinks are not equal
    EXPECT_NE(drink1, drink2);
}
