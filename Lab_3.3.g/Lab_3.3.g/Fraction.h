
#pragma once
#include "DigitString.h"

class Fraction : public DigitString {
    unsigned short fractionalPart;
public:
    Fraction();
    Fraction(std::string intP, unsigned short fracP);
    Fraction(const Fraction& other);

    unsigned short GetFractionalPart() const { return fractionalPart; }
    void SetFractionalPart(unsigned short f) { fractionalPart = f; }

    bool Init(std::string intP, unsigned short fracP);
    void Read();
    void Display() const;
    std::string toString() const;

    Fraction& operator=(const Fraction& other);

    // Arithmetic for fractions
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
};