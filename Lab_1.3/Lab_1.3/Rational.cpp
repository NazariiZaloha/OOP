#include "Rational.h"
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

static int gcd(int x, int y)
{
    x = abs(x);
    y = abs(y);

    while (y != 0)
    {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

Rational::Rational() : a(0), b(1) {}

Rational::Rational(int numerator, int denominator)
{
    if (!Init(numerator, denominator))
    {
        cout << "Invalid parameters!" << endl;
        exit(1);
    }
}

void Rational::Reduce()
{
    int g = gcd(a, b);
    a /= g;
    b /= g;

    if (b < 0)
    {
        a = -a;
        b = -b;
    }
}

int Rational::getA() const { return a; }
int Rational::getB() const { return b; }

void Rational::setA(int value)
{
    a = value;
    Reduce();
}

void Rational::setB(int value)
{
    if (value == 0)
    {
        cout << "Denominator cannot be zero!" << endl;
        exit(1);
    }
    b = value;
    Reduce();
}

bool Rational::Init(int numerator, int denominator)
{
    if (denominator == 0)
        return false;

    a = numerator;
    b = denominator;
    Reduce();
    return true;
}

void Rational::Read()
{
    int numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    if (!Init(numerator, denominator))
    {
        cout << "Invalid rational number!" << endl;
        exit(1);
    }
}

string Rational::toString() const
{
    stringstream ss;
    ss << a << "/" << b;
    return ss.str();
}

void Rational::Display() const
{
    cout << "Rational: " << toString() << endl;
    cout << "Value: " << value() << endl;
}

double Rational::value() const
{
    return 1.0 * a / b;
}

Rational Rational::add(const Rational& r) const
{
    Rational tmp;
    tmp.a = a * r.b + b * r.a;
    tmp.b = b * r.b;
    tmp.Reduce();
    return tmp;
}

Rational Rational::sub(const Rational& r) const
{
    Rational tmp;
    tmp.a = a * r.b - b * r.a;
    tmp.b = b * r.b;
    tmp.Reduce();
    return tmp;
}

Rational Rational::mul(const Rational& r) const
{
    Rational tmp;
    tmp.a = a * r.a;
    tmp.b = b * r.b;
    tmp.Reduce();
    return tmp;
}

Rational makeRational(int numerator, int denominator)
{
    if (denominator == 0)
    {
        cout << "Error: denominator cannot be zero!" << endl;
        exit(1);
    }

    Rational r;
    r.Init(numerator, denominator);
    return r;
}
