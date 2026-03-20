#include "RationalPublic.h"

RationalPublic& RationalPublic::operator=(const RationalPublic& r) {
    if (this != &r) {
        Init(r.getA(), r.getB());
    }
    return *this;
}

RationalPublic operator+(RationalPublic l, RationalPublic r) {
    Rational tmp = l.add(r);
    return RationalPublic(tmp.getA(), tmp.getB());
}
RationalPublic operator-(RationalPublic l, RationalPublic r) {
    Rational tmp = l.sub(r);
    return RationalPublic(tmp.getA(), tmp.getB());
}

RationalPublic operator*(RationalPublic l, RationalPublic r) {
    Rational tmp = l.mul(r);
    return RationalPublic(tmp.getA(), tmp.getB());
}

RationalPublic RationalPublic::operator++(int) {
    RationalPublic tmp = *this;
    Init(getA() + getB(), getB());
    return tmp;
}

RationalPublic& RationalPublic::operator++() {
    Init(getA() + getB(), getB());
    return *this;
}

RationalPublic RationalPublic::operator--(int) {
    RationalPublic tmp = *this;
    Init(getA() - getB(), getB());
    return tmp;
}

RationalPublic& RationalPublic::operator--() {
    Init(getA() - getB(), getB());
    return *this;
}

RationalPublic::operator std::string() {
    return toString();
}