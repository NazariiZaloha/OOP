#include <iostream>
#include "ListArray.h"

int main() {
    ListArray a(5, 1); // 5 елементів = 1
    ListArray b(5, 2);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    ListArray c = a + b;

    std::cout << "a + b: " << c << std::endl;

    std::cout << "Sum: " << c.sum() << std::endl;
    std::cout << "Average: " << c.average() << std::endl;

    return 0;
}