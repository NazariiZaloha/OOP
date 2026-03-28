
#include "DigitString.h"

DigitString::DigitString() : value("0") {}
DigitString::DigitString(std::string v) { if (!Init(v)) value = "0"; }
DigitString::DigitString(const DigitString& other) : value(other.value) {}

bool DigitString::Init(std::string v) {
    for (char c : v) {
        if (!isdigit(c) && c != '-') return false;
    }
    value = v;
    return true;
}

void DigitString::Read() {
    std::string temp;
    do {
        std::cout << "Enter integer (string of digits): ";
        std::cin >> temp;
    } while (!Init(temp));
}

void DigitString::Display() const { std::cout << value; }
std::string DigitString::toString() const { return value; }

DigitString& DigitString::operator=(const DigitString& other) {
    value = other.value;
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

DigitString operator+(const DigitString& a, const DigitString& b) {
    return DigitString(std::to_string(std::stoll(a.value) + std::stoll(b.value)));
}

DigitString operator-(const DigitString& a, const DigitString& b) {
    return DigitString(std::to_string(std::stoll(a.value) - std::stoll(b.value)));
}

DigitString operator*(const DigitString& a, const DigitString& b) {
    return DigitString(std::to_string(std::stoll(a.value) * std::stoll(b.value)));
}

bool operator==(const DigitString& a, const DigitString& b) { return a.value == b.value; }
bool operator<(const DigitString& a, const DigitString& b) { return std::stoll(a.value) < std::stoll(b.value); }

std::ostream& operator<<(std::ostream& out, const DigitString& obj) {
    out << obj.value;
    return out;
}

std::istream& operator>>(std::istream& in, DigitString& obj) {
    std::string s;
    in >> s;
    obj.Init(s);
    return in;
}