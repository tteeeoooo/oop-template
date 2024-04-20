#include <gtest/gtest.h>
#include "noalc.h"

TEST(SuiteName, OutputOperatorTest) {
    // Cream un obiect de tip NoAlc cu anumite valori
    NoAlc drink("Soda", 2.5, 100);

    // Cream un std::ostringstream pentru a captura ieșirea
    std::ostringstream oss;
    
    // Folosim operatorul << pentru a scrie obiectul în std::ostringstream
    oss << drink;

    // Verificăm dacă ieșirea obținută este cea așteptată
    EXPECT_EQ(oss.str(), "Soda 2.5 100");
}
