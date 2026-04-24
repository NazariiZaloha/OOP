#pragma once
#include <string>
#include <iostream>

class DigitString {
private:
    std::string value;
    void validate(const std::string& s) const; 

public:
   
    DigitString();
    DigitString(const std::string& s);
    DigitString(const DigitString& other);
    virtual ~DigitString() {}

   
    void setValue(const std::string& s);
    std::string getValue() const;

    
    bool Init(const std::string& s);
    void Read();
    void Display() const;
    std::string toString() const;

   
    DigitString& operator=(const DigitString& other);
    DigitString& operator++();    
    DigitString operator++(int);  
    DigitString& operator--();   
    DigitString operator--(int);  

    operator std::string() const; 

    
    friend bool operator==(const DigitString& a, const DigitString& b);
    friend bool operator!=(const DigitString& a, const DigitString& b);
    friend DigitString operator+(const DigitString& a, const DigitString& b);
    friend DigitString operator-(const DigitString& a, const DigitString& b);
};