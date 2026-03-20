#pragma once
#include "Rational.h"

class RationalPrivate : private Rational {
public:
    RationalPrivate(int a = 0, int b = 1);

    RationalPrivate operator+(RationalPrivate r);

    void show();
};