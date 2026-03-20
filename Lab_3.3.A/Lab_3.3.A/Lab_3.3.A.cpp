#include <iostream>
#include "Rational.h"
#include "RationalPublic.h"
#include "RationalPrivate.h"

using namespace std;

int main() {

    Rational r1, r2(1, 2), r3 = r2;

    cin >> r1;

    cout << r1 << endl;
    cout << r2 << endl;

    Rational r4 = r1.add(r2);
    cout << "Add: " << r4 << endl;

    Rational arr[2] = { Rational(1,2), Rational(3,4) };

    RationalPublic p1(1, 2), p2(3, 4);
    RationalPublic p3 = p1 + p2;

    cout << "p3: " << p3 << endl;

    p3++;
    cout << "after ++: " << p3 << endl;

    string s = (string)p3;
    cout << s << endl;

    RationalPrivate pr1(1, 2), pr2(2, 3);
    RationalPrivate pr3 = pr1 + pr2;
    pr3.show();

    cout << "Size: " << sizeof(Rational) << endl;

#pragma pack(push,1)
    cout << "Size pack(1): " << sizeof(Rational) << endl;
#pragma pack(pop)

    return 0;
}