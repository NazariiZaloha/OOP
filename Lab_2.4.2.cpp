#include "Polinom.h"
#include <iostream>
using namespace std;

int main() {
    double arr1[5] = { 1, 2, 3, 4, 5 };
    Polinom p1(5, arr1);
    Polinom p2 = p1;  

    cout << "p1: "; p1.print();
    cout << "p2: "; p2.print();

    Polinom p3;
    p3 = p1 + p2;
    cout << "p1 + p2: " << p3 << endl;

    p3[0] = 10;  
    cout << "After modifying p3[0]: " << p3 << endl;

    cout << "p3 evaluated at x=2: " << p3.evaluate(2) << endl;

    Polinom deriv = p3.derivative();
    cout << "Derivative: " << deriv << endl;

    Polinom integ = p3.integral();
    cout << "Integral: " << integ << endl;

    p1.printSize();

    Polinom p4("1 0 2 3");
    cout << "Polinom from string: " << p4 << endl;

    return 0;
}