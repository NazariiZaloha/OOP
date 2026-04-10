#include "solver.h"
#include <cmath>

double solve_v1(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    if (d < 0) throw d;
    return (-b + std::sqrt(d)) / (2 * a);
}

double solve_v2(double a, double b, double c) throw() {
    double d = b * b - 4 * a * c;
    if (d < 0) throw d; // Викличе unexpected() через специфікацію throw()
    return (-b + std::sqrt(d)) / (2 * a);
}

double solve_v3(double a, double b, double c) throw(std::domain_error) {
    double d = b * b - 4 * a * c;
    if (d < 0) throw std::domain_error("Negative discriminant (v3)");
    return (-b + std::sqrt(d)) / (2 * a);
}

double solve_v4(double a, double b, double c) throw(EmptyException) {
    double d = b * b - 4 * a * c;
    if (d < 0) throw EmptyException();
    return (-b + std::sqrt(d)) / (2 * a);
}

double solve_v5(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    if (d < 0) throw IndependentException(a, b, c, d);
    return (-b + std::sqrt(d)) / (2 * a);
}

double solve_v6(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    if (d < 0) throw DerivedException("Discriminant error (v6)", d);
    return (-b + std::sqrt(d)) / (2 * a);
}