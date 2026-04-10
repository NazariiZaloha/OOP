#include <iostream>
#include "Array.h"

int main() {
    try {
        Array a(-2, 2);
        std::cout << "Enter array a:\n";
        std::cin >> a;

        Array b(-2, 2);
        std::cout << "Enter array b:\n";
        std::cin >> b;

        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;

        std::cout << "a + b: " << (a + b) << std::endl;
        std::cout << "a - b: " << (a - b) << std::endl;

        std::cout << "a * 2: " << (a * 2) << std::endl;

        std::cout << "Sum: " << a.sum() << std::endl;
        std::cout << "Average: " << a.average() << std::endl;
        std::cout << "Max: " << a.max() << std::endl;
        std::cout << "Min: " << a.min() << std::endl;

    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}