#include <gtest/gtest.h>
#include "cart.h"

TEST(CartTest, ProductDeleteTest) {
    // Se creează un obiect Cart cu băuturi de test
    std::vector<Drink*> drinks = {new NoAlc("TestDrink", 5.0), new NoAlc("TestDrink2", 7.0)};
    Cart cart(drinks, 12.0, {5.0, 7.0});

    // Se șterge un produs din coș și se verifică prețul și numărul de produse
    cart.productDelete(1);
    EXPECT_EQ(cart.cartPrice(), 7.0);
    EXPECT_EQ(cart.getDrinks(cart).size(), 1);

    // Se eliberează memoria pentru băuturi
    for (auto drink : drinks) {
        delete drink;
    }
}
