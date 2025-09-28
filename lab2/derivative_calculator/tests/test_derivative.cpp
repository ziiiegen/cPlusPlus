#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include "../include/derivative.h"
using namespace Catch;

// Тестовые функции для проверки
double square(double x) { return x * x; }
double sine(double x) { return std::sin(x); }
double linear(double x) { return 3 * x + 2; }

// TEST_CASE - это макрос Catch2 для создания группы тестов
// "Derivative of basic functions" - название тестовой группы
// "[derivative]" - тег для фильтрации тестов
TEST_CASE("Derivative of basic functions", "[derivative]") {
    
    // SECTION - создает подраздел внутри тестовой группы
    SECTION("Derivative of x^2 should be 2x") {
        // REQUIRE - проверяет условие, если ложно - тест падает
        // Approx(4.0).margin(1e-4) - проверка с допуском ±0.0001
        REQUIRE(std::abs(derivative(square, 2.0) - 4.0) < 1e-4);
        REQUIRE(std::abs(derivative(square, 0.0) - 0.0) < 1e-4);
        REQUIRE(std::abs(derivative(square, -1.0) - (-2.0)) < 1e-4);
    }
    
    SECTION("Derivative of sin(x) should be cos(x)") {
        // Производная sin(x) в точке 0 должна быть cos(0) = 1
        // Производная sin(x) в точке π/2 должна быть cos(π/2) = 0
        REQUIRE(std::abs(derivative(sine, 0.0) - 1.0) < 1e-4);
        REQUIRE(std::abs(derivative(sine, M_PI/2) - 0.0) < 1e-4);
    }
    
    SECTION("Derivative of linear function should be constant") {
        // Производная линейной функции 3x+2 всегда равна 3
        REQUIRE(std::abs(derivative(linear, 1.0) - 3.0) < 1e-4);
        REQUIRE(std::abs(derivative(linear, 10.0) - 3.0) < 1e-4);
        REQUIRE(std::abs(derivative(linear, -5.0) - 3.0) < 1e-4);
    }
}

// Вторая группа тестов для граничных случаев
TEST_CASE("Edge cases", "[derivative]") {
    
    SECTION("Small step sizes") {
        // Проверяем, что очень малый шаг не ломает вычисления
        // Допуск увеличен, т.к. при очень малых h может накапливаться ошибка
        REQUIRE(std::abs(derivative(square, 1.0, 1e-8) - 2.0) < 1e-3);
    }
    
    SECTION("Invalid step size should throw") {
        // REQUIRE_THROWS_AS - проверяет, что код бросает конкретное исключение
        REQUIRE_THROWS_AS(derivative(square, 1.0, 0.0), std::invalid_argument);
        REQUIRE_THROWS_AS(derivative(square, 1.0, -1.0), std::invalid_argument);
    }
}