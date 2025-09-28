#include <iostream>
#include <cmath>
#include "../include/derivative.h"

double square(double x) {
    return x * x;
}

int main() {
    std::cout << "=== Numerical Derivative Demo ===" << std::endl;
    
    double x = 2.0;
    double analytical = 2 * x;
    double numerical = derivative(square, x);
    
    std::cout << "Function: f(x) = x^2" << std::endl;
    std::cout << "At x = " << x << std::endl;
    std::cout << "Analytical derivative: " << analytical << std::endl;
    std::cout << "Numerical derivative: " << numerical << std::endl;
    std::cout << "Error: " << std::abs(analytical - numerical) << std::endl;
    
    return 0;
}