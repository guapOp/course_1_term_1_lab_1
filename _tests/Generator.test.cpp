#include <gtest/gtest.h>
#include "../generator.h"

TEST(GeneratorTest, Complexity1) {
    using namespace Generator;

    // генерация пароля длиной 10 со сложностью 1
    std::string password = Generator::pass(10, 1);

    // длина должна быть 10
    EXPECT_EQ(password.length(), 10);

    // проверяем, что каждый символ является либо цифрой, либо строчной буквой
    for (char c : password) {
        EXPECT_TRUE(isdigit(c) || islower(c)) << "Unexpected character in password: " << c;
    }
}

TEST(GeneratorTest, Complexity2) {
    using namespace Generator;

    // генерация пароля длиной 12 со сложностью 2 (цифры, строчные и заглавные буквы)
    std::string password = Generator::pass(12, 2);

    // длина должна быть 12
    EXPECT_EQ(password.length(), 12);

    // проверяем, что каждый символ является цифрой, строчной или заглавной буквой
    for (char c : password) {
        EXPECT_TRUE(isdigit(c) || islower(c) || isupper(c)) << "Unexpected character in password: " << c;
    }
}

TEST(GeneratorTest, Complexity3) {
    using namespace Generator;

    // генерация пароля длиной 16 со сложностью 3 (цифры, буквы и спецсимволы)
    std::string password = Generator::pass(16, 3);

    // длина должна быть 16
    EXPECT_EQ(password.length(), 16);

    // проверяем, что каждый символ является цифрой, строчной буквой, заглавной буквой или спецсимволом
    std::string special = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    for (char c : password) {
        EXPECT_TRUE(isdigit(c) || islower(c) || isupper(c) || special.find(c) != std::string::npos) << "Unexpected character in password: " << c;
    }
}

TEST(GeneratorTest, InvalidComplexity) {
    using namespace Generator;

    // проверка некорректной сложности
    std::string password = Generator::pass(10, 4);  // Неправильная сложность

    // ожидаем, что пароль пустой
    EXPECT_EQ(password, "");
}

TEST(GeneratorTest, ZeroLength) {
    using namespace Generator;

    // генерация пароля длиной 0
    std::string password = Generator::pass(0, 1);

    // ожидаем, что пароль пустой
    EXPECT_EQ(password.length(), 0);
}


TEST(GeneratorTest, NegativeLength) {
    using namespace Generator;

    // генерация пароля с отрицательной длиной
    std::string password = Generator::pass(-5, 1);

    // ожидаем, что пароль пустой
    EXPECT_EQ(password.length(), 0);
}

