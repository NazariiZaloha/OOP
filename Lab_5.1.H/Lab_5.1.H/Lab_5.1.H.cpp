#include <iostream>
#include "Fraction.h"

#pragma pack(push, 1)
struct PackedCheck {
    char s[sizeof(std::string)]; 
    unsigned short f;
};
#pragma pack(pop)

int main() {
    try {
        std::cout << "--- Object Creation ---" << std::endl;
        Fraction f1("10.50");
        Fraction f2("5.75");

        std::cout << "f1: "; f1.Display();
        std::cout << "f2: "; f2.Display();

        std::cout << "\n--- Arithmetic & Comparison ---" << std::endl;
        Fraction fSum = f1 + f2;
        std::cout << "f1 + f2 = " << fSum.toString() << std::endl;
        std::cout << "f1 > f2 ? " << (f1 > f2 ? "Yes" : "No") << std::endl;

        std::cout << "\n--- Increment (Unary Operation) ---" << std::endl;
        std::cout << "f1 before f1++: " << f1.toString() << std::endl;
        f1++;
        std::cout << "f1 after f1++: " << f1.toString() << std::endl;

        std::cout << "\n--- Object Arrays ---" << std::endl;
        Fraction* arr = new Fraction[2];
        arr[0].Init("1.1");
        arr[1].Init("2.2");
        for (int i = 0; i < 2; i++) {
            std::cout << "arr[" << i << "] = " << arr[i].toString() << std::endl;
        }
        delete[] arr;

        std::cout << "\n--- Sizeof Verification ---" << std::endl;
        std::cout << "Fraction size (standard): " << sizeof(Fraction) << " bytes" << std::endl;
        std::cout << "Packed structure size: " << sizeof(PackedCheck) << " bytes" << std::endl;

        std::cout << "\n--- Exception Handling Test ---" << std::endl;
        Fraction errorTest("invalid_input.data");

    }
    catch (const std::exception& e) {
        std::cerr << "\nException caught: " << e.what() << std::endl;
    }

    return 0;
}