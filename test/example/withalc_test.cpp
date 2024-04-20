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

TEST(WithAlcTest, AgeCheckTest) {
    // Cream un obiect de tip WithAlc cu numele și prețul oarecare și 12% alcool
    WithAlc drink("Whiskey", 10.0, 12);
    
    // Redirecționăm fluxurile de intrare și ieșire pentru a simula introducerea vârstei
    std::istringstream iss("20");
    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    std::streambuf* oldCin = std::cin.rdbuf(iss.rdbuf());
    
    // Verificăm dacă funcția ageCheck() returnează corect false pentru o vârstă sub 21 de ani
    EXPECT_FALSE(drink.ageCheck());
    
    // Restaurăm fluxurile de intrare și ieșire pentru a reveni la comportamentul normal
    std::cout.rdbuf(oldCout);
    std::cin.rdbuf(oldCin);
}

TEST(WithAlcTest, DescriptionTest) {
    // Cream un obiect de tip WithAlc cu numele și prețul oarecare și 12% alcool
    WithAlc drink("Wine", 10.0, 12);
    
    // Redirecționăm ieșirea standard pentru a captura mesajele afișate
    testing::internal::CaptureStdout();
    
    // Apelăm funcția de descriere pentru obiectul nostru WithAlc
    drink.description();
    
    // Obținem ieșirea capturată
    std::string output = testing::internal::GetCapturedStdout();
    
    // Verificăm dacă descrierea conține informații despre alcool
    EXPECT_NE(output.find("This drink contains alcohol in a percentage of"), std::string::npos);
}




