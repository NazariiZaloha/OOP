#include "DigitalString.h"
#include <stdexcept>
#include <algorithm>

void DigitString::validate(const std::string& s) const {
    if (s.empty()) throw std::invalid_argument("String is empty");
    if (!std::all_of(s.begin(), s.end(), ::isdigit)) {
        throw std::invalid_argument("String contains non-digit characters");
    }
}

DigitString::DigitString() : value("0") {}

DigitString::DigitString(const std::string& s) {
    if (!Init(s)) throw std::invalid_argument("Initialization failed: invalid format");
}

DigitString::DigitString(const DigitString& other) : value(other.value) {}

void DigitString::setValue(const std::string& s) {
    validate(s);
    value = s;
}

std::string DigitString::getValue() const { return value; }

bool DigitString::Init(const std::string& s) {
    try {
        validate(s);
        value = s;
        return true;
    }
    catch (...) {
        value = "0";
        return false;
    }
}

void DigitString::Read() {
    std::string s;
    std::cout << "Enter an integer: ";
    std::cin >> s;
    if (!Init(s)) throw std::invalid_argument("Input error: non-digit characters detected");
}

void DigitString::Display() const {
    std::cout << value;
}

std::string DigitString::toString() const { return value; }

DigitString& DigitString::operator=(const DigitString& other) {
    if (this != &other) value = other.value;
    return *this;
}

DigitString& DigitString::operator++() {
    long long val = std::stoll(value);
    value = std::to_string(++val);
    return *this;
}

DigitString DigitString::operator++(int) {
    DigitString temp(*this);
    operator++();
    return temp;
}

DigitString& DigitString::operator--() {
    long long val = std::stoll(value);
    value = std::to_string(--val);
    return *this;
}

DigitString DigitString::operator--(int) {
    DigitString temp(*this);
    operator--();
    return temp;
}

DigitString::operator std::string() const { return value; }

bool operator==(const DigitString& a, const DigitString& b) { return a.value == b.value; }
bool operator!=(const DigitString& a, const DigitString& b) { return !(a == b); }

DigitString operator+(const DigitString& a, const DigitString& b) {
    return DigitString(std::to_string(std::stoll(a.value) + std::stoll(b.value)));
}

DigitString operator-(const DigitString& a, const DigitString& b) {
    long long res = std::stoll(a.value) - std::stoll(b.value);
    if (res < 0) throw std::underflow_error("Negative result (DigitString represents non-negative digits)");
    return DigitString(std::to_string(res));
}