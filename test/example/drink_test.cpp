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

TEST(DrinkTest, AssignmentOperatorTest) {
    // Create two drinks with different initial values
    Drink drink1("Coffee", 2.5);
    Drink drink2("Tea", 3.0);
    
    // Assign drink2 to drink1
    drink1 = drink2;
    
    // Check if drink1 now has the properties of drink2
    EXPECT_EQ(drink1.getDrinkName(), "Tea");
    EXPECT_DOUBLE_EQ(drink1.getDrinkPrice(), 3.0);
}
