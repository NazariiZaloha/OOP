#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // exit()

class Pair {
protected:
    int first;
    int second;

public:
    // Constructors
    Pair() : first(0), second(0) {}
    Pair(int f, int s) {
        if (f < 0 || s < 0) { std::cerr << "Error: values must be non-negative\n"; exit(1); }
        first = f; second = s;
    }
    Pair(const Pair& p) : first(p.first), second(p.second) {}

    // Accessors
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    void setFirst(int f) { if (f >= 0) first = f; else std::cerr << "Invalid value\n"; }
    void setSecond(int s) { if (s >= 0) second = s; else std::cerr << "Invalid value\n"; }

    // Initialization method
    void Init(int f, int s) { setFirst(f); setSecond(s); }

    // Prefix and postfix increment/decrement
    Pair& operator++() { ++first; ++second; return *this; }      // prefix
    Pair operator++(int) { Pair temp = *this; ++(*this); return temp; } // postfix
    Pair& operator--() { --first; --second; return *this; }      // prefix
    Pair operator--(int) { Pair temp = *this; --(*this); return temp; } // postfix

    // Assignment
    Pair& operator=(const Pair& p) { first = p.first; second = p.second; return *this; }

    // Convert to string
    std::string toString() const { return "(" + std::to_string(first) + "," + std::to_string(second) + ")"; }

    // Comparison operators
    bool operator>(const Pair& p) const { return (first > p.first) || (first == p.first && second > p.second); }
    bool operator==(const Pair& p) const { return first == p.first && second == p.second; }

    // Friend functions for input/output
    friend std::ostream& operator<<(std::ostream& os, const Pair& p) {
        os << "(" << p.first << "," << p.second << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Pair& p) {
        std::cout << "Enter first: "; is >> p.first;
        std::cout << "Enter second: "; is >> p.second;
        return is;
    }
};

// makePair helper function
inline Pair makePair(int f, int s) { return Pair(f, s); }