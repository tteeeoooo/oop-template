#include <gtest/gtest.h>
#include "drink.h"
#include "withalc.h"

TEST(WithAlcTest, PriceModifierTest) {
    // Cream un obiect de tip WithAlc cu un preț de 3.0 și 5% alcool
    WithAlc drink("Beer", 3.0, 5);
    
    // Calculăm prețul modificat folosind funcția priceModifier()
    double modifiedPrice = drink.priceModifier();
    
    // Prețul modificat ar trebui să fie prețul inițial plus TVA-ul plus acciza
    // Acciza pentru băuturile alcoolice este de 5% din prețul cu TVA-ul
    double expectedPrice = 3.0 + (3.0 * 19 / 100) + ((3.0 + (3.0 * 19 / 100)) * 5 / 100);
    
    // Verificăm dacă prețul modificat calculat este cel așteptat
    EXPECT_DOUBLE_EQ(modifiedPrice, expectedPrice);
}
