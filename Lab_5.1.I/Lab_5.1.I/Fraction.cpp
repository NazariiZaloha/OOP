#include "Fraction.h"
#include <iostream>

Fraction::Fraction() : DigitString(), fractionalPart(0) {}

Fraction::Fraction(const std::string& s) : DigitString() {
    if (!Init(s)) throw std::invalid_argument("Fraction: Format must be 'int.fract'");
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
            fractionalPart = static_cast<unsigned short>(std::stoi(s.substr(dotPos + 1)));
        }
        return true;
    }
    catch (...) { return false; }
}

void Fraction::Read() {
    std::string s;
    std::cout << "Enter fraction (int.fract): "; std::cin >> s;
    if (!Init(s)) throw std::runtime_error("Fraction: Read failed");
}

std::string Fraction::toString() const {
    return DigitString::toString() + "." + std::to_string(fractionalPart);
}

void Fraction::Display() const { std::cout << this->toString() << std::endl; }

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
    long long iSum = std::stoll(a.getValue()) + std::stoll(b.getValue());
    int fSum = a.fractionalPart + b.fractionalPart;
    if (fSum >= 1000) { iSum++; fSum -= 1000; }

    Fraction res;
    res.setValue(std::to_string(iSum));
    res.fractionalPart = static_cast<unsigned short>(fSum);
    return res;
}

bool operator>(const Fraction& a, const Fraction& b) {
    if (std::stoll(a.getValue()) != std::stoll(b.getValue()))
        return std::stoll(a.getValue()) > std::stoll(b.getValue());
    return a.fractionalPart > b.fractionalPart;
}