#include "Rational.h"
#include <iostream>
using namespace std;

int main()
{
    // 1️⃣ Default constructor + setters
    Rational r1;
    r1.setA(2);
    r1.setB(4);
    r1.Display();

    // 2️⃣ Constructor with parameters
    Rational r2(3, 5);
    r2.Display();

    // 3️⃣ Using make function
    Rational r3 = makeRational(10, 20);
    r3.Display();

    // 4️⃣ Arithmetic operations
    Rational sum = r1.add(r2);
    Rational diff = r1.sub(r2);
    Rational prod = r1.mul(r2);

    cout << "\nOperations:" << endl;
    cout << r1.toString() << " + " << r2.toString()
        << " = " << sum.toString() << endl;

    cout << r1.toString() << " - " << r2.toString()
        << " = " << diff.toString() << endl;

    cout << r1.toString() << " * " << r2.toString()
        << " = " << prod.toString() << endl;

    // 5️⃣ Array of objects
    Rational arr[3] = {
        Rational(1, 2),
        Rational(2, 3),
        Rational(3, 4)
    };

    cout << "\nArray of rationals:" << endl;
    for (int i = 0; i < 3; i++)
        arr[i].Display();

    // 6️⃣ Input example
    Rational r4;
    r4.Read();
    r4.Display();

    return 0;
}
