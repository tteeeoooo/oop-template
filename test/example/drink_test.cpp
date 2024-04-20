#include <gtest/gtest.h>
#include "drink.h" // Presupunând că aici este inclus fișierul header pentru clasa Drink

TEST(DrinkTest, PriceModifier) {
    // Testăm funcția priceModifier() din clasa Drink

    // Inițializăm un obiect de tip Drink (aceasta nu este posibil deoarece Drink este o clasă abstractă)
    // În loc de inițializare directă, vom folosi o clasă derivată (MockDrink) pentru a testa funcția virtuală pură

    // Cream un obiect de tip MockDrink cu un preț specific
    double expectedPrice = 5.0;
    MockDrink mockDrink(expectedPrice);

    // Apelăm funcția priceModifier()
    double result = mockDrink.priceModifier();

    // Verificăm dacă prețul întors de funcție este corect
    EXPECT_EQ(result, expectedPrice);
}
