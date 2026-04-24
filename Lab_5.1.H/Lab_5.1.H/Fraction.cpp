#include "Fraction.h"
#include <sstream>

Fraction::Fraction() : DigitString("0"), fractionalPart(0) {}

Fraction::Fraction(const std::string& s) {
    if (!Init(s)) throw std::invalid_argument("Format must be 'integer.fractional'");
}

Fraction::Fraction(const Fraction& other)
    : DigitString(other), fractionalPart(other.fractionalPart) {
}

bool Fraction::Init(const std::string& s) {
    size_t dotPos = s.find('.');
    try {
        if (dotPos == std::string::npos) {
            DigitString::Init(s);
            fractionalPart = 0;
        }
        else {
            DigitString::Init(s.substr(0, dotPos));
            std::string fPart = s.substr(dotPos + 1);
            if (fPart.length() > 5) fPart = fPart.substr(0, 5);
            fractionalPart = static_cast<unsigned short>(std::stoi(fPart));
        }
        return true;
    }
    catch (...) {
        return false;
    }
}

void Fraction::Read() {
    std::string s;
    std::cout << "Enter a fractional number (format: integer.fractional): ";
    std::cin >> s;
    if (!Init(s)) throw std::invalid_argument("Input error: invalid number format");
}

void Fraction::Display() const {
    std::cout << toString() << std::endl;
}

std::string Fraction::toString() const {
    return DigitString::getValue() + "." + std::to_string(fractionalPart);
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        DigitString::operator=(other);
        fractionalPart = other.fractionalPart;
    }
    return *this;
}

Fraction& Fraction::operator++() {
    DigitString::operator++();
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    operator++();
    return temp;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
    long long integerSum = std::stoll(a.getValue()) + std::stoll(b.getValue());
    int fractSum = a.fractionalPart + b.fractionalPart;

    
    if (fractSum >= 1000) {
        integerSum += fractSum / 1000;
        fractSum %= 1000;
    }

    Fraction res;
    res.setValue(std::to_string(integerSum));
    res.setFractional(static_cast<unsigned short>(fractSum));
    return res;
}

bool operator>(const Fraction& a, const Fraction& b) {
    if (std::stoll(a.getValue()) > std::stoll(b.getValue())) return true;
    if (std::stoll(a.getValue()) < std::stoll(b.getValue())) return false;
    return a.fractionalPart > b.fractionalPart;
}

bool operator<(const Fraction& a, const Fraction& b) { return b > a; }