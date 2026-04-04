#ifndef BITSTRING_H
#define BITSTRING_H

#include "Array.h"

class BitString : public Array {
public:
    BitString(int size = 1, unsigned char value = 0);

    BitString* add(const Array& other) const override;

    BitString operator&(const BitString& other) const;
    BitString operator|(const BitString& other) const;
    BitString operator^(const BitString& other) const;
    BitString operator~() const;

    BitString shiftLeft(int n) const;
    BitString shiftRight(int n) const;

    void print() const override;
    const char* getType() const override;
};

#endif