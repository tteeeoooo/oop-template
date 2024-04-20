#include <gtest/gtest.h>
#include "account.h" // Include fișierul header al clasei Account

TEST(AccountTest, InputVisual) {
    Account account; // Inițializăm un obiect al clasei Account

    // Testăm fiecare caz posibil al switch-ului în funcția inputVisual
    EXPECT_EQ(account.inputVisual(1), "Premium plus");
    EXPECT_EQ(account.inputVisual(2), "Premium");
    EXPECT_EQ(account.inputVisual(3), "Business casual");
    EXPECT_EQ(account.inputVisual(0), "abort mission");
}

TEST(AccountTest, Exc) {
    Account account;
    std::stringstream input_stream("1\n2\n3\n");
    std::cin.rdbuf(input_stream.rdbuf()); 

    EXPECT_EQ(account.exc(), 1); 
    EXPECT_EQ(account.exc(), 2); 

    ASSERT_THROW(account.exc(), std::invalid_argument);
}


// #include <gtest/gtest.h>
// #include "account.h"

// TEST(AccountTest, ConstructorTest) {
//     Account acc;
//     EXPECT_EQ(acc.getName(), "");
// }

// TEST(AccountTest, ParameterizedConstructorTest) {
//     Account acc("test_user", "test_password");
//     EXPECT_EQ(acc.getName(), "test_user");
// }

// TEST(AccountTest, GetNameTest) {
//     Account acc("test_user", "test_password");
//     EXPECT_EQ(acc.getName(), "test_user");
// }

// TEST(AccountTest, ExcTest) {
//     std::stringstream input_stream("1\n");
//     std::stringstream output_stream;
//     std::streambuf *old_cin = std::cin.rdbuf(input_stream.rdbuf());
//     std::streambuf *old_cout = std::cout.rdbuf(output_stream.rdbuf());

//     Account acc;
//     int result = acc.exc();
//     EXPECT_EQ(result, 1);

//     // Resetare cin și cout
//     std::cin.rdbuf(old_cin);
//     std::cout.rdbuf(old_cout);
// }

// TEST(AccountTest, UserReadTest) {
//     // Redirectez cin și cout pentru a simula input/output
//     std::stringstream input_stream("test_user\ntest_password\n0\n");
//     std::stringstream output_stream;
//     std::streambuf *old_cin = std::cin.rdbuf(input_stream.rdbuf());
//     std::streambuf *old_cout = std::cout.rdbuf(output_stream.rdbuf());

//     Account acc;
//     acc.userRead();

//     std::cin.rdbuf(old_cin);
//     std::cout.rdbuf(old_cout);

//     EXPECT_EQ(acc.getName(), "test_user");
// }

// TEST(AccountTest, PremiumTextTest) {
//     // Redirectez cout pentru a captura output-ul
//     std::stringstream output_stream;
//     std::streambuf *old_cout = std::cout.rdbuf(output_stream.rdbuf());

//     Account::premiumText();

//     std::cout.rdbuf(old_cout);

//     std::string output = output_stream.str();
//     EXPECT_TRUE(output.find("Discover the advantages of premium") != std::string::npos);
// }

// TEST(AccountTest, InputVisualTest) {
//     EXPECT_EQ(Account::inputVisual(1), "Premium plus");
//     EXPECT_EQ(Account::inputVisual(2), "Premium");
//     EXPECT_EQ(Account::inputVisual(3), "Business casual");
//     EXPECT_EQ(Account::inputVisual(0), "abort mission");
//     // Test suplimentar pentru alt input
//     EXPECT_EQ(Account::inputVisual(4), "");
// }

// TEST(AccountTest, SaveTest) {
//     std::stringstream output_stream;
//     std::streambuf *old_cout = std::cout.rdbuf(output_stream.rdbuf());

//     Account acc("test_user", "test_password");
//     acc.save();

//     std::cout.rdbuf(old_cout);

//     std::ifstream file("date.txt");
//     std::string username, password;
//     file >> username >> password;
//     file.close();

//     EXPECT_EQ(username, "test_user");
//     EXPECT_EQ(password, "test_password");
// }

// TEST(AccountTest, AssignmentOperatorTest) {
//     Account acc1("user1", "pass1");
//     Account acc2("user2", "pass2");

//     acc2 = acc1;

//     EXPECT_EQ(acc2.getName(), "user1");
// }

// TEST(AccountTest, InsertionOperatorTest) {
//     Account acc("test_user", "test_password");
//     std::stringstream output_stream;
//     output_stream << acc;
//     std::string output = output_stream.str();
//     EXPECT_TRUE(output.find("Username: test_user") != std::string::npos);
//     EXPECT_TRUE(output.find("Password: test_password") != std::string::npos);
// }

// TEST(AccountTest, ExtractionOperatorTest) {
//     Account acc;
//     std::stringstream input_stream("test_user test_password");
//     input_stream >> acc;
//     EXPECT_EQ(acc.getName(), "test_user");
// }

// TEST(AccountTest, DestructorTest) {
//     Account* acc = new Account("test_user", "test_password");
//     delete acc;
// }

