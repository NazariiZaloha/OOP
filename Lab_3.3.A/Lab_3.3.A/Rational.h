#pragma once
#include <iostream>
#include <string>

using namespace std;

class Rational {
private:
    int a, b;

    void Reduce();

public:
    Rational();
    Rational(int a, int b);
    Rational(const Rational& r);

    void Init(int a, int b);

    int getA() const;
    int getB() const;

    void setA(int val);
    void setB(int val);

    double value();

    Rational add(const Rational& r);
    Rational sub(const Rational& r);
    Rational mul(const Rational& r);

    string toString();
    void Display();
    void Read();

    friend ostream& operator<<(ostream& out, const Rational& r);
    friend istream& operator>>(istream& in, Rational& r);
};