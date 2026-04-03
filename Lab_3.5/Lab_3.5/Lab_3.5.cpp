#include "Array.h"
#include "Decimal.h"
#include <iostream>

int main() {
    // Array demo
    Array arr(5, 0);
    arr.input();
    arr.output();
    arr[2] = 10;
    arr.output();

    // Decimal demo
    Decimal a(12345);
    Decimal b(67890);

    std::cout << "a = "; a.output();
    std::cout << "b = "; b.output();

    Decimal c = a + b;
    std::cout << "a + b = "; c.output();

    // Input Decimal from keyboard
    Decimal d;
    std::cout << "Enter a number: ";
    d.input();
    std::cout << "You entered: "; d.output();

    return 0;
}