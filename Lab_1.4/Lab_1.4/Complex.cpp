#include <iostream>
#include <sstream>
#include "Complex.h"

using namespace std;

// Конструктори
Complex::Complex() {
    real = 0;
    imag = 0;
}

Complex::Complex(double r, double i) {
    Init(r, i);
}

// Методи доступу
double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

bool Complex::setReal(double r) {
    real = r;   // для комплексного числа обмежень немає
    return true;
}

bool Complex::setImag(double i) {
    imag = i;
    return true;
}

// Init
bool Complex::Init(double r, double i) {
    return setReal(r) && setImag(i);
}

// Read
void Complex::Read() {
    double r, i;
    cout << "Real part: ";
    cin >> r;
    cout << "Imaginary part: ";
    cin >> i;

    Init(r, i);
}

// Display
void Complex::Display() const {
    cout << toString() << endl;
}

// toString
string Complex::toString() const {
    stringstream ss;
    if (imag >= 0)
        ss << real << " + " << imag << "i";
    else
        ss << real << " - " << -imag << "i";
    return ss.str();
}

// Операції
Complex Complex::add(const Complex& other) const {
    return Complex(real + other.real,
        imag + other.imag);
}

Complex Complex::subtract(const Complex& other) const {
    return Complex(real - other.real,
        imag - other.imag);
}

Complex Complex::multiply(const Complex& other) const {
    return Complex(
        real * other.real - imag * other.imag,
        real * other.imag + imag * other.real
    );
}