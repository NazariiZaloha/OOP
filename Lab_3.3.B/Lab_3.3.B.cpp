#include <iostream>
#include "pair.h"
#include "triad.h"
#include "rational.h"

int main() {
    std::cout << "=== Pair ===\n";
    Pair p1 = makePair(2, 3);
    Pair p2;
    std::cin >> p2;
    std::cout << "p1: " << p1 << ", p2: " << p2 << "\n";
    std::cout << "p1 > p2? " << (p1 > p2) << "\n";

    std::cout << "\nPrefix and Postfix increment/decrement:\n";
    std::cout << "p1: " << p1 << "\n";
    std::cout << "++p1: " << ++p1 << "\n";
    std::cout << "p1++: " << p1++ << "\n";
    std::cout << "p1: " << p1 << "\n";

    std::cout << "\n=== Triad ===\n";
    Triad t1 = makeTriad(1, 2, 3);
    Triad t2 = makeTriad(1, 2, 4);
    std::cout << "t1: " << t1.toString() << ", t2: " << t2.toString() << "\n";
    std::cout << "t2 > t1? " << (t2 > t1) << "\n";

    std::cout << "\nIncrement/Decrement Triad:\n";
    std::cout << "t1: " << t1.toString() << "\n";
    std::cout << "++t1: " << (++t1).toString() << "\n";
    std::cout << "t1--: " << (t1--).toString() << "\n";
    std::cout << "t1: " << t1.toString() << "\n";

    std::cout << "\n=== Rational ===\n";
    Rational r1 = makeRational(3, 4);
    Rational r2;
    std::cin >> r2;
    std::cout << "r1: " << r1 << ", r2: " << r2 << "\n";
    Rational r3 = r1.add(r2);
    Rational r4 = r1.sub(r2);
    Rational r5 = r1.mul(r2);
    std::cout << "r1+r2 = " << r3 << "\n";
    std::cout << "r1-r2 = " << r4 << "\n";
    std::cout << "r1*r2 = " << r5 << "\n";
    std::cout << "Value of r3: " << r3.value() << "\n";

    std::cout << "\nIncrement/Decrement Rational:\n";
    std::cout << "r1: " << r1 << "\n";
    std::cout << "++r1: " << ++r1 << "\n";
    std::cout << "r1--: " << r1-- << "\n";
    std::cout << "r1: " << r1 << "\n";

    std::cout << "\nClass sizes:\n";
#pragma pack(1)
    std::cout << "sizeof(Pair) = " << sizeof(Pair) << "\n";
    std::cout << "sizeof(Triad) = " << sizeof(Triad) << "\n";
    std::cout << "sizeof(Rational) = " << sizeof(Rational) << "\n";
#pragma pack()
    return 0;
}