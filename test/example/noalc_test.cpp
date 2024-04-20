#include <gtest/gtest.h>
#include <sstream> // Pentru std::ostringstream
#include "noalc.h" // Asigură-te că calea către headerul corect este inclusă aici

// Verificăm dacă operatorul << produce ieșirea corectă pentru obiectele de tip NoAlc
TEST(NoAlcTest, OutputOperatorTest) {
    // Cream un obiect de tip NoAlc cu anumite valori
    NoAlc drink("Soda", 2.5, 100);

    // Cream un std::ostringstream pentru a captura ieșirea
    std::ostringstream oss;
    
    // Folosim operatorul << pentru a scrie obiectul în std::ostringstream
    oss << drink;

    // Verificăm dacă ieșirea obținută este cea așteptată
    EXPECT_EQ(oss.str(), "Soda 2.5 100");
}

// Mai poți adăuga teste suplimentare pentru alte cazuri dacă este necesar

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
