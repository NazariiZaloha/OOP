#include "Polinom.h"
#include <sstream>
#include <cmath>


void Polinom::updateCount() {
    count = 0;
    for (int i = 0; i < size; ++i)
        if (fabs(coeffs[i]) > 1e-10) count++;
}


Polinom::Polinom() {
    size = 100;
    count = 0;
    for (int i = 0; i < size; ++i) coeffs[i] = 0;
}

Polinom::Polinom(int n, double arr[]) {
    if (n > 100) n = 100;
    size = n;
    for (int i = 0; i < size; ++i)
        coeffs[i] = arr ? arr[i] : 0;
    updateCount();
}

Polinom::Polinom(const Polinom& other) {
    size = other.size;
    count = other.count;
    for (int i = 0; i < size; ++i)
        coeffs[i] = other.coeffs[i];
}

Polinom::Polinom(const string& s) {
    size = 100;
    count = 0;
    for (int i = 0; i < size; ++i) coeffs[i] = 0;

    stringstream ss(s);
    int i = 0;
    double val;
    while (ss >> val && i < 100) {
        coeffs[i++] = val;
    }
    size = i;
    updateCount();
}


double Polinom::getCoeff(int i) const {
    if (i >= 0 && i < size) return coeffs[i];
    return 0;
}

void Polinom::setCoeff(int i, double value) {
    if (i >= 0 && i < size) coeffs[i] = value;
    updateCount();
}

int Polinom::getSize() const { return size; }
int Polinom::getCount() const { return count; }

Polinom& Polinom::operator=(const Polinom& other) {
    if (this == &other) return *this;
    size = other.size;
    count = other.count;
    for (int i = 0; i < size; ++i)
        coeffs[i] = other.coeffs[i];
    return *this;
}

Polinom& Polinom::operator+=(const Polinom& other) {
    int n = min(size, other.size);
    for (int i = 0; i < n; ++i)
        coeffs[i] += other.coeffs[i];
    updateCount();
    return *this;
}

Polinom& Polinom::operator-=(const Polinom& other) {
    int n = min(size, other.size);
    for (int i = 0; i < n; ++i)
        coeffs[i] -= other.coeffs[i];
    updateCount();
    return *this;
}

Polinom& Polinom::operator*=(const Polinom& other) {
    double result[100] = { 0 };
    int n = min(size, 100);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < other.size && i + j < 100; ++j)
            result[i + j] += coeffs[i] * other.coeffs[j];
    }
    for (int i = 0; i < 100; ++i) coeffs[i] = result[i];
    updateCount();
    return *this;
}

double& Polinom::operator[](int i) {
    if (i < 0 || i >= size) throw out_of_range("Index out of range");
    return coeffs[i];
}


double Polinom::evaluate(double x) const {
    double result = 0;
    for (int i = size - 1; i >= 0; --i)
        result = result * x + coeffs[i];
    return result;
}

Polinom Polinom::derivative() const {
    double deriv[100] = { 0 };
    for (int i = 1; i < size; ++i)
        deriv[i - 1] = coeffs[i] * i;
    return Polinom(size - 1, deriv);
}

Polinom Polinom::integral() const {
    double integ[100] = { 0 };
    for (int i = 0; i < size - 1; ++i)
        integ[i + 1] = coeffs[i] / (i + 1);
    return Polinom(size, integ);
}

Polinom::operator string() const {
    string s;
    for (int i = 0; i < size; ++i)
        s += to_string(coeffs[i]) + " ";
    return s;
}

void Polinom::print() const {
    for (int i = 0; i < size; ++i)
        cout << coeffs[i] << " ";
    cout << endl;
}

void Polinom::printSize() const {
    cout << "Size of class: " << sizeof(*this) << " bytes\n";
}

Polinom operator+(Polinom a, const Polinom& b) { return a += b; }
Polinom operator-(Polinom a, const Polinom& b) { return a -= b; }
Polinom operator*(Polinom a, const Polinom& b) { return a *= b; }

bool operator==(const Polinom& a, const Polinom& b) {
    int n = max(a.getSize(), b.getSize());
    for (int i = 0; i < n; ++i)
        if (fabs(a.getCoeff(i) - b.getCoeff(i)) > 1e-10) return false;
    return true;
}

bool operator!=(const Polinom& a, const Polinom& b) { return !(a == b); }

istream& operator>>(istream& in, Polinom& p) {
    for (int i = 0; i < p.getSize(); ++i)
        in >> p[i];
    return in;
}

ostream& operator<<(ostream& out, const Polinom& p) {
    for (int i = 0; i < p.getSize(); ++i)
        out << p.getCoeff(i) << " ";
    return out;
}