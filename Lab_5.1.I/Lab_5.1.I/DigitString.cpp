#include "DigitString.h"
#include <algorithm>
#include <stdexcept>

void DigitString::validate(const std::string& s) const {
    if (s.empty()) throw std::invalid_argument("DigitString: String cannot be empty");
    if (!std::all_of(s.begin(), s.end(), ::isdigit))
        throw std::invalid_argument("DigitString: String must contain digits only");
}

DigitString::DigitString() : Object(), value("0") {}

DigitString::DigitString(const std::string& s) : Object() {
    if (!Init(s)) throw std::invalid_argument("DigitString: Invalid format");
}

DigitString::DigitString(const DigitString& other) : Object(), value(other.value) {}

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

void DigitString::setValue(const std::string& s) {
    validate(s);
    value = s;
}

void DigitString::Read() {
    std::string s;
    std::cout << "Enter digits: "; std::cin >> s;
    if (!Init(s)) throw std::runtime_error("DigitString: Input validation failed");
}

void DigitString::Display() const { std::cout << value; }
std::string DigitString::toString() const { return value; }

DigitString& DigitString::operator=(const DigitString& other) {
    if (this != &other) value = other.value;
    return *this;
}

DigitString& DigitString::operator++() {
    value = std::to_string(std::stoll(value) + 1);
    return *this;
}

DigitString DigitString::operator++(int) {
    DigitString temp(*this);
    operator++();
    return temp;
}

DigitString& DigitString::operator--() {
    long long v = std::stoll(value);
    if (v <= 0) throw std::underflow_error("DigitString: Cannot be less than zero");
    value = std::to_string(v - 1);
    return *this;
}

DigitString DigitString::operator--(int) {
    DigitString temp(*this);
    operator--();
    return temp;
}

bool operator==(const DigitString& a, const DigitString& b) { return a.value == b.value; }
DigitString operator+(const DigitString& a, const DigitString& b) {
    return DigitString(std::to_string(std::stoll(a.value) + std::stoll(b.value)));
}