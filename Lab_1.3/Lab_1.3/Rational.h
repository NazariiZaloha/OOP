#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>

class Rational
{
private:
    int a; // numerator
    int b; // denominator

    void Reduce(); // private reduction

public:
    Rational();
    Rational(int numerator, int denominator);

    // Getters (const)
    int getA() const;
    int getB() const;

    // Setters (with validation)
    void setA(int value);
    void setB(int value);

    bool Init(int numerator, int denominator);

    void Read();
    void Display() const;
    std::string toString() const;

    double value() const;

    Rational add(const Rational& r) const;
    Rational sub(const Rational& r) const;
    Rational mul(const Rational& r) const;
};

Rational makeRational(int numerator, int denominator);

#endif
