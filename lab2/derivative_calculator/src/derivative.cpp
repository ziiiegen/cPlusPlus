#include "../include/derivative.h"
#include <stdexcept>

double derivative(double (*func)(double), double x, double h) {
    if (h <= 0) {
        throw std::invalid_argument("The h step must be positive and not equal to zero.");
    }
    return (func(x + h) - func(x - h)) / (2 * h);
}