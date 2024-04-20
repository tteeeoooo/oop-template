#include <gtest/gtest.h>
#include "noalc.h" // Presupunând că aici este inclus fișierul header pentru clasa NoAlc

TEST(NoAlcTest, PriceModifier) {
    // Inițializăm un obiect de tip NoAlc cu un preț specific
    NoAlc noAlc("Non-alcoholic Drink", 100.0, 200); // Presupunând că există un constructor corespunzător în clasa NoAlc

    // Obținem prețul folosind funcția priceModifier() din clasa NoAlc
    double result = noAlc.priceModifier();

    // Calculăm prețul așteptat pentru testare
    double expectedPrice = 100.0 + (100.0 * 19) / 100;

    // Verificăm dacă prețul întors de funcție este cel așteptat
    EXPECT_DOUBLE_EQ(result, expectedPrice);
}
