#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

class Complex {
private:
    double real;
    double imag;

public:
    // Конструктори
    Complex();
    Complex(double r, double i);

    // Методи доступу
    double getReal() const;
    double getImag() const;

    bool setReal(double r);
    bool setImag(double i);

    // Обов’язкові методи
    bool Init(double r, double i);
    void Read();
    void Display() const;
    std::string toString() const;

    // Арифметичні операції
    Complex add(const Complex& other) const;
    Complex subtract(const Complex& other) const;
    Complex multiply(const Complex& other) const;
};

#endif#pragma once
