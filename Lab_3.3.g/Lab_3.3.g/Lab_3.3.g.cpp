// main.cpp
#include <iostream>
#include "Fraction.h"

void ShowClassSizes() {
    std::cout << "\n--- Memory Alignment Info ---" << std::endl;
    std::cout << "Size of DigitString: " << sizeof(DigitString) << " bytes" << std::endl;
    std::cout << "Size of Fraction: " << sizeof(Fraction) << " bytes" << std::endl;

#pragma pack(push, 1)
    struct PackedExample {
        char s[32];
        unsigned short f;
    };
#pragma pack(pop)
    std::cout << "Estimated size with #pragma pack(1): " << sizeof(PackedExample) << " bytes" << std::endl;
}

int main() {
    std::cout << "Initial Object count: " << Object::GetCount() << std::endl;

    // Creating objects
    Fraction f1("15", 750);
    Fraction f2;
    std::cout << "Input data for f2:" << std::endl;
    f2.Read();

    std::cout << "\nf1: "; f1.Display();
    std::cout << "f2: "; f2.Display();

    // Operations demonstration
    Fraction sum = f1 + f2;
    std::cout << "Result of f1 + f2: " << sum.toString() << std::endl;

    if (f1 > f2) std::cout << "f1 is greater than f2" << std::endl;

    // Incrementing the integer part via inherited operator
    ++f1;
    std::cout << "f1 after prefix increment: " << f1.toString() << std::endl;

    // Array of objects
    std::cout << "\nCreating an array of 3 Fractions..." << std::endl;
    Fraction* arr = new Fraction[3];
    std::cout << "Object count now: " << Object::GetCount() << std::endl;

    delete[] arr;
    std::cout << "Object count after deletion: " << Object::GetCount() << std::endl;

    ShowClassSizes();

    return 0;
}