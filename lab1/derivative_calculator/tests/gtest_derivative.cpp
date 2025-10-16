#include "../include/derivative.h"
#include <gtest/gtest.h>
#include <cmath>

// Тестовые функции для проверки
double square(double x) { return x * x; }
double sine(double x) { return std::sin(x); }

// Тест 1: Проверяем производную x^2
TEST(DerivativeTest, SquareFunction) {
    double result = derivative(square, 2.0, 0.0001);
    EXPECT_NEAR(result, 4.0, 0.01); 
}

// Тест 2: Проверяем производную sin(x)
TEST(DerivativeTest, SinFunction) {
    double result = derivative(sine, 0.0, 0.0001);
    EXPECT_NEAR(result, 1.0, 0.01);
}

// Тест 3: Проверяем обработку ошибок
TEST(DerivativeTest, InvalidStep) {
    // Должны получить ошибку при h=0
    EXPECT_THROW(derivative(square, 2.0, 0.0), std::invalid_argument);
    
    // Должны получить ошибку при отрицательном h
    EXPECT_THROW(derivative(square, 2.0, -0.1), std::invalid_argument);
}

