#include "BitString.h"

BitString::BitString(int size, unsigned char value)
    : Array(size, value) {
}

BitString* BitString::add(const Array& other) const {
    const BitString* b = dynamic_cast<const BitString*>(&other);
    if (!b) throw std::invalid_argument("Wrong type for BitString add");

    BitString* result = new BitString(size);
    for (int i = 0; i < size; i++)
        (*result)[i] = data[i] ^ (*b)[i];

    return result;
}

BitString BitString::operator&(const BitString& other) const {
    BitString result(size);
    for (int i = 0; i < size; i++)
        result[i] = data[i] & other[i];
    return result;
}

BitString BitString::operator|(const BitString& other) const {
    BitString result(size);
    for (int i = 0; i < size; i++)
        result[i] = data[i] | other[i];
    return result;
}

BitString BitString::operator^(const BitString& other) const {
    BitString result(size);
    for (int i = 0; i < size; i++)
        result[i] = data[i] ^ other[i];
    return result;
}

BitString BitString::operator~() const {
    BitString result(size);
    for (int i = 0; i < size; i++)
        result[i] = (~data[i]) & 1;
    return result;
}

BitString BitString::shiftLeft(int n) const {
    BitString result(size);
    for (int i = size - 1; i >= n; i--)
        result[i] = data[i - n];
    for (int i = 0; i < n; i++)
        result[i] = 0;
    return result;
}

BitString BitString::shiftRight(int n) const {
    BitString result(size);
    for (int i = 0; i < size - n; i++)
        result[i] = data[i + n];
    for (int i = size - n; i < size; i++)
        result[i] = 0;
    return result;
}

void BitString::print() const {
    for (int i = size - 1; i >= 0; i--)
        std::cout << (int)data[i];
    std::cout << std::endl;
}

const char* BitString::getType() const { return "BitString"; }