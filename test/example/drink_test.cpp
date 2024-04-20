#include <gtest/gtest.h>
#include "drink.h" // Presupunând că aici este inclus fișierul header pentru clasa Drink

TEST(SuiteName, TestName) {
    // Testăm funcția priceModifier() din clasa Drink

    // Inițializăm un obiect de tip MockDrink cu un preț specific
    double expectedPrice = 5.0;
    MockDrink mockDrink(expectedPrice);

    // Apelăm funcția priceModifier()
    double result = mockDrink.priceModifier();

    // Verificăm dacă prețul întors de funcție este corect
    EXPECT_EQ(result, expectedPrice);
}
