#pragma once
#include "Rational.h"

class RationalPublic : public Rational {
public:
    using Rational::Rational;

    RationalPublic& operator=(const RationalPublic& r);

    friend RationalPublic operator+(RationalPublic l, RationalPublic r);
    friend RationalPublic operator-(RationalPublic l, RationalPublic r);
    friend RationalPublic operator*(RationalPublic l, RationalPublic r);

    RationalPublic operator++(int);
    RationalPublic& operator++();

    RationalPublic operator--(int);
    RationalPublic& operator--();

    operator std::string();
};