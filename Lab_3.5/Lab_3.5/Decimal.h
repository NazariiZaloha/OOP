#pragma once
#include "Array.h"
#include <string>

class Decimal : public Array {
private:
    unsigned char digits[MAX_SIZE]; // цифри числа
    bool sign; // true = додатнє, false = від'ємне
    int realSize; // кількість цифр

public:
    Decimal();
    Decimal(long long num);

    void input();
    void output() const;
    std::string toString() const;

    Decimal operator+(const Decimal& other) const;
};