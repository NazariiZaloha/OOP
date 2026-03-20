#pragma once
#include "pair.h"

class Triad : public Pair {
protected:
    int third;
public:
    // Constructors
    Triad() : Pair(), third(0) {}
    Triad(int f, int s, int t) : Pair(f, s), third(t) {}
    Triad(const Triad& t) : Pair(t), third(t.third) {}

    // Accessors
    int getThird() const { return third; }
    void setThird(int t) { third = t; }

    // Prefix and postfix increment/decrement
    Triad& operator++() { ++first; ++second; ++third; return *this; }   // prefix
    Triad operator++(int) { Triad temp = *this; ++(*this); return temp; } // postfix
    Triad& operator--() { --first; --second; --third; return *this; }   // prefix
    Triad operator--(int) { Triad temp = *this; --(*this); return temp; } // postfix

    // Assignment
    Triad& operator=(const Triad& t) { Pair::operator=(t); third = t.third; return *this; }

    // Convert to string
    std::string toString() const {
        return "(" + std::to_string(first) + "," + std::to_string(second) + "," + std::to_string(third) + ")";
    }

    // Comparison operator
    bool operator>(const Triad& t) const {
        return (first > t.first) || (first == t.first && second > t.second) || (first == t.first && second == t.second && third > t.third);
    }
};

// makeTriad helper function
inline Triad makeTriad(int f, int s, int t) { return Triad(f, s, t); }