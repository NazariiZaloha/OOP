#pragma once
#include "pair.h"
#include <iostream>
#include <numeric>
#include <string>

class Rational : public Pair {
private:
    void Reduce() { 
        int gcd = std::gcd(first, second); 
        first /= gcd; second /= gcd; 
    }

public:
    // Constructors
    Rational() : Pair(0,1) {}
    Rational(int a,int b) : Pair(a,b) { 
        if(b==0){ std::cerr<<"Denominator cannot be 0\n"; exit(1); } 
        Reduce(); 
    }
    Rational(const Rational& r) : Pair(r.first,r.second) {}

    // Accessors
    int getNumerator() const { return first; }
    int getDenominator() const { return second; }
    void setNumerator(int a) { first=a; Reduce(); }
    void setDenominator(int b) { if(b!=0){second=b; Reduce();} else std::cerr<<"Error\n"; }

    // Unary operation
    double value() const { return 1.0*first/second; }

    // Binary operations
    Rational add(const Rational& r) const { return Rational(first*r.second + second*r.first, second*r.second); }
    Rational sub(const Rational& r) const { return Rational(first*r.second - second*r.first, second*r.second); }
    Rational mul(const Rational& r) const { return Rational(first*r.first, second*r.second); }

    // Prefix and postfix increment/decrement
    Rational& operator++() { first += second; Reduce(); return *this; }    // prefix
    Rational operator++(int) { Rational temp = *this; ++(*this); return temp; } // postfix
    Rational& operator--() { first -= second; Reduce(); return *this; }    // prefix
    Rational operator--(int) { Rational temp = *this; --(*this); return temp; } // postfix

    // Friend functions for input/output
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) { os << r.first << "/" << r.second; return os; }
    friend std::istream& operator>>(std::istream& is, Rational& r) {
        std::cout << "Enter numerator: "; is >> r.first;
        std::cout << "Enter denominator: "; is >> r.second;
        if(r.second==0){ std::cerr<<"Denominator cannot be 0\n"; exit(1);}
        r.Reduce();
        return is;
    }
};

// makeRational helper function
inline Rational makeRational(int a,int b) { return Rational(a,b); }