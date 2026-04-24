#pragma once
#include "DigitalString.h"

class Fraction : public DigitString {
private:
    unsigned short fractionalPart;

public:
    Fraction();
    Fraction(const std::string& s); 
    Fraction(const Fraction& other);

    void setFractional(unsigned short f) { fractionalPart = f; }
    unsigned short getFractional() const { return fractionalPart; }

    
    bool Init(const std::string& s);
    void Read();
    void Display() const;
    std::string toString() const;

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator=(const Fraction& other);

    
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
    friend bool operator<(const Fraction& a, const Fraction& b);
};