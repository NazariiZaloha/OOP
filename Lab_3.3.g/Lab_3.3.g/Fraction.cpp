
#include "Fraction.h"

Fraction::Fraction() : DigitString("0"), fractionalPart(0) {}
Fraction::Fraction(std::string intP, unsigned short fracP) : DigitString(intP), fractionalPart(fracP) {}
Fraction::Fraction(const Fraction& other) : DigitString(other), fractionalPart(other.fractionalPart) {}

bool Fraction::Init(std::string intP, unsigned short fracP) {
    return DigitString::Init(intP);
}

void Fraction::Read() {
    DigitString::Read();
    std::cout << "Enter fractional part (unsigned short): ";
    std::cin >> fractionalPart;
}

std::string Fraction::toString() const {
    return DigitString::toString() + "." + std::to_string(fractionalPart);
}

void Fraction::Display() const {
    std::cout << toString() << std::endl;
}

Fraction& Fraction::operator=(const Fraction& other) {
    DigitString::operator=(other);
    fractionalPart = other.fractionalPart;
    return *this;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
    long long i1 = std::stoll(a.GetValue()), i2 = std::stoll(b.GetValue());
    unsigned int fSum = a.fractionalPart + b.fractionalPart;

    // Example logic: carry over if sum exceeds 1000
    if (fSum >= 1000) {
        i1++;
        fSum -= 1000;
    }
    return Fraction(std::to_string(i1 + i2), (unsigned short)fSum);
}

bool operator>(const Fraction& a, const Fraction& b) {
    if (std::stoll(a.GetValue()) != std::stoll(b.GetValue()))
        return std::stoll(a.GetValue()) > std::stoll(b.GetValue());
    return a.fractionalPart > b.fractionalPart;
}