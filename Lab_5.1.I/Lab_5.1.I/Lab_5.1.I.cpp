#include <iostream>
#include "Fraction.h"

void demo() {
    std::cout << "--- Creating f1 and f2 ---" << std::endl;
    Fraction f1("10.500");
    Fraction f2("5.700");
    std::cout << "Current Objects: " << Object::getCount() << std::endl;

    std::cout << "Sum: " << (f1 + f2).toString() << std::endl;

    std::cout << "--- Prefix Increment on f1 ---" << std::endl;
    (++f1).Display();
}

int main() {
    try {
        std::cout << "Initial Count: " << Object::getCount() << std::endl;
        demo();
        std::cout << "Count after demo() scope: " << Object::getCount() << std::endl;

        std::cout << "\n--- Array demo ---" << std::endl;
        Fraction* arr = new Fraction[3];
        std::cout << "Count with array: " << Object::getCount() << std::endl;
        delete[] arr;
        std::cout << "Count after delete: " << Object::getCount() << std::endl;

        std::cout << "\n--- Exception demo ---" << std::endl;
        Fraction fError("abc.def");

    }
    catch (const std::exception& e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
    }
    return 0;
}