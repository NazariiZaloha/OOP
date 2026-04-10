#include "exceptions.h"
#include <iostream>
#include <cstdlib>

void my_terminate() {
    std::cerr << "Custom Terminate: Unhandled exception! Exiting..." << std::endl;
    std::exit(1);
}

void my_unexpected() {
    std::cerr << "Custom Unexpected: Exception violation!" << std::endl;
    std::terminate();
}

IndependentException::IndependentException(double _a, double _b, double _c, double _d)
    : a(_a), b(_b), c(_c), d(_d) {
}

DerivedException::DerivedException(const std::string& msg, double d)
    : std::runtime_error(msg), discriminant(d) {}