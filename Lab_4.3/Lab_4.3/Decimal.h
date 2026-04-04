#ifndef DECIMAL_H
#define DECIMAL_H

#include "Array.h"

class Decimal : public Array {
public:
    int sign; // 1 або -1

    Decimal(int size = 1, unsigned char value = 0, int sign = 1);

    Decimal* add(const Array& other) const override;

    Decimal operator+(const Decimal& other) const;
    Decimal operator-(const Decimal& other) const;

    bool operator==(const Decimal& other) const;
    bool operator<(const Decimal& other) const;

    void print() const override;
    const char* getType() const override;
};

#endif