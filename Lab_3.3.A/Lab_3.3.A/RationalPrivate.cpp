#include "RationalPrivate.h"

RationalPrivate::RationalPrivate(int a, int b) : Rational(a, b) {}

RationalPrivate RationalPrivate::operator+(RationalPrivate r) {
    Rational res = add(r);
    return RationalPrivate(res.getA(), res.getB());
}

void RationalPrivate::show() {
    Display();
}