#include "Decimal.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

Decimal::Decimal() : Array(), sign(true), realSize(0) {
    for (int i = 0; i < MAX_SIZE; i++)
        digits[i] = 0;
}

Decimal::Decimal(long long num) : Array() {
    if (num == 0) {
        realSize = 1;
        digits[0] = 0;
        sign = true;
    }
    else {
        sign = (num >= 0);
        num = std::abs(num);
        realSize = 0;
        while (num > 0) {
            digits[realSize++] = num % 10;
            num /= 10;
        }
    }
}

std::string Decimal::toString() const {
    std::string s = sign ? "" : "-";
    for (int i = realSize - 1; i >= 0; i--)
        s += ('0' + digits[i]);
    return s;
}

void Decimal::input() {
    std::string s;
    std::cin >> s;
    sign = (s[0] != '-');
    if (!sign) s = s.substr(1);

    realSize = s.size();
    if (realSize > MAX_SIZE) {
        std::cerr << "Error: number is too large!\n";
        exit(1);
    }
    for (int i = 0; i < realSize; i++)
        digits[i] = s[realSize - i - 1] - '0';
}

void Decimal::output() const {
    std::cout << toString() << std::endl;
}

Decimal Decimal::operator+(const Decimal& other) const {
    Decimal result;
    if (sign != other.sign) {
        std::cerr << "Error: addition of numbers with different signs is not implemented\n";
        exit(1);
    }

    int carry = 0;
    int maxSize = std::max(realSize, other.realSize);
    result.realSize = maxSize;

    for (int i = 0; i < maxSize; i++) {
        int sum = carry;
        if (i < realSize) sum += digits[i];
        if (i < other.realSize) sum += other.digits[i];
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        if (maxSize >= MAX_SIZE) {
            std::cerr << "Error: number overflow!\n";
            exit(1);
        }
        result.digits[maxSize] = carry;
        result.realSize++;
    }
    result.sign = sign;
    return result;
}