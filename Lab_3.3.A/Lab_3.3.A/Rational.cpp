#include "Rational.h"
#include <sstream>
#include <cmath>

void Rational::Reduce() {
    int x = abs(a), y = abs(b);
    while (y != 0) {
        int t = x % y;
        x = y;
        y = t;
    }
    a /= x;
    b /= x;
    if (b < 0) { a = -a; b = -b; }
}

Rational::Rational() { a = 0; b = 1; }

Rational::Rational(int a, int b) {
    this->a = a;
    this->b = (b != 0 ? b : 1);
    Reduce();
}

Rational::Rational(const Rational& r) {
    a = r.a;
    b = r.b;
}

void Rational::Init(int a, int b) {
    this->a = a;
    this->b = (b != 0 ? b : 1);
    Reduce();
}

int Rational::getA() const { return a; }
int Rational::getB() const { return b; }

void Rational::setA(int val) { a = val; }
void Rational::setB(int val) { if (val != 0) b = val; }

double Rational::value() {
    return 1.0 * a / b;
}

Rational Rational::add(const Rational& r) {
    return Rational(a * r.b + b * r.a, b * r.b);
}

Rational Rational::sub(const Rational& r) {
    return Rational(a * r.b - b * r.a, b * r.b);
}

Rational Rational::mul(const Rational& r) {
    return Rational(a * r.a, b * r.b);
}

string Rational::toString() {
    stringstream ss;
    ss << a << "/" << b;
    return ss.str();
}

void Rational::Display() {
    cout << a << "/" << b << endl;
}

void Rational::Read() {
    cout << "a = "; cin >> a;
    do {
        cout << "b (!=0) = ";
        cin >> b;
    } while (b == 0);
    Reduce();
}

ostream& operator<<(ostream& out, const Rational& r) {
    out << r.a << "/" << r.b;
    return out;
}

istream& operator>>(istream& in, Rational& r) {
    cout << "Enter numerator (a): ";
    in >> r.a;

    do {
        cout << "Enter denominator (b != 0): ";
        in >> r.b;
    } while (r.b == 0);

    r.Reduce();
    return in;
}