#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

// --- Підміна системних функцій ---
void my_terminate();
void my_unexpected();

// --- Класи винятків ---

// Варіант 4: Порожній клас
class EmptyException {};

// Варіант 5: Незалежний клас з полями
class IndependentException {
public:
    double a, b, c, d;
    IndependentException(double _a, double _b, double _c, double _d);
};

// Варіант 6: Нащадок від std::exception
class DerivedException : public std::runtime_error {
public:
    double discriminant;
    DerivedException(const std::string& msg, double d);
};

#endif