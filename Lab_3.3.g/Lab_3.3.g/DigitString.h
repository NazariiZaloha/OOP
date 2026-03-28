// DigitString.h
#pragma once
#include "Object.h"
#include <string>
#include <iostream>

class DigitString : public Object {
    std::string value;
public:
    DigitString();
    DigitString(std::string v);
    DigitString(const DigitString& other);

    // Гетери/Сетери
    void SetValue(std::string v);
    std::string GetValue() const { return value; }

    // Методи за Лабораторною 1.7
    bool Init(std::string v);
    void Read();
    void Display() const;
    std::string toString() const;

    // Операції
    DigitString& operator=(const DigitString& other);
    DigitString& operator++();    // префіксний
    DigitString operator++(int);  // постфіксний
    DigitString& operator--();
    DigitString operator--(int);

    // Бінарні операції (дружні функції)
    friend DigitString operator+(const DigitString& a, const DigitString& b);
    friend DigitString operator-(const DigitString& a, const DigitString& b);
    friend DigitString operator*(const DigitString& a, const DigitString& b);
    friend bool operator==(const DigitString& a, const DigitString& b);
    friend bool operator<(const DigitString& a, const DigitString& b);

    friend std::ostream& operator<<(std::ostream& out, const DigitString& obj);
    friend std::istream& operator>>(std::istream& in, DigitString& obj);
};