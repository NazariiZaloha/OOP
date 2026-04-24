#pragma once
#include "Object.h"
#include <string>
#include <iostream>

class DigitString : public Object {
private:
    std::string value;
    void validate(const std::string& s) const;

public:
    DigitString();
    explicit DigitString(const std::string& s);
    DigitString(const DigitString& other);
    virtual ~DigitString() override = default;

    // Standard methods from Lab 1.7
    bool Init(const std::string& s);
    void Read();
    void Display() const;
    std::string toString() const;

    // Getters/Setters
    std::string getValue() const { return value; }
    void setValue(const std::string& s);

    // Operators (Unary - Methods)
    DigitString& operator=(const DigitString& other);
    DigitString& operator++();    // Prefix
    DigitString operator++(int);  // Postfix
    DigitString& operator--();
    DigitString operator--(int);

    // Type conversion
    explicit operator std::string() const { return value; }

    // Binary Operators (Friends)
    friend bool operator==(const DigitString& a, const DigitString& b);
    friend DigitString operator+(const DigitString& a, const DigitString& b);
};