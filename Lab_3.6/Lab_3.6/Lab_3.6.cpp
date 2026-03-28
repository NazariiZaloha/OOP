#include <iostream>
#include <iomanip>
#include "D4.h"

using namespace std;

int main() {
    // Basic setup for output formatting
    cout << "=== Creating object D4 (Hierarchy Entry Point) ===" << endl;

    // Initializing the object: B1, B2 -> D1; D2; (D1, D2) -> D3; D3 -> D4
    // Parameters: b1, b2, d1, d2, d3, d4
    D4 objectD4(1, 2, 10, 20, 30, 40);

    cout << "\n=== Displaying Object Hierarchy (show() method) ===" << endl;
    objectD4.show();

    cout << "\n=== Object Memory Allocation (sizeof) ===" << endl;
    cout << "Size of B1 class: " << sizeof(B1) << " bytes" << endl;
    cout << "Size of B2 class: " << sizeof(B2) << " bytes" << endl;
    cout << "Size of D1 class: " << sizeof(D1) << " bytes" << endl;
    cout << "Size of D2 class: " << sizeof(D2) << " bytes" << endl;
    cout << "Size of D3 class: " << sizeof(D3) << " bytes" << endl;
    cout << "Size of D4 class: " << sizeof(D4) << " bytes" << endl;

    cout << "\n=== Starting Destruction Process ===" << endl;
    // Object goes out of scope here, triggering destructors in reverse order
    return 0;
}