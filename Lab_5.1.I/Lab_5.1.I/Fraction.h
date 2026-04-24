#pragma once
#include "DigitString.h"

class Fraction : public DigitString {
private:
    unsigned short fractionalPart;

public:
    Fraction();
    explicit Fraction(const std::string& s);
    Fraction(const Fraction& other);
    virtual ~Fraction() override = default;

    // Overrides
    bool Init(const std::string& s);
    void Read();
    void Display() const;
    std::string toString() const;

    // Operators
    Fraction& operator=(const Fraction& other);
    Fraction& operator++(); // Prefix
    Fraction operator++(int); // Postfix

    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
};