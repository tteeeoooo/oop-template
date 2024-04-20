#include <gtest/gtest.h>
#include "noalc.h" // Presupunând că aici este inclus fișierul header pentru clasa NoAlc

TEST(SuiteName, TestName) {
    // Testăm funcția priceModifier() din clasa NoAlc

    // Inițializăm un obiect de tip NoAlc
    NoAlc noAlc;

    // Setăm un preț specific pentru testare
    noAlc.price = 100; // Accesăm direct membrul de date price

    // Calculăm prețul așteptat pentru testare
    double expectedPrice = 100 + (100 * 19) / 100;

    // Obținem prețul folosind funcția priceModifier() din clasa NoAlc
    double result = noAlc.priceModifier();

    // Verificăm dacă prețul întors de funcție este corect
    EXPECT_EQ(result, expectedPrice);
}
