#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

    // 🔹 1. Створення різними способами
    Complex a;                  // конструктор за замовчуванням
    Complex b(2, 3);            // з параметрами
    Complex c;
    c.Init(4, -5);              // через Init

    cout << "Object b: ";
    b.Display();

    cout << "Object c: ";
    c.Display();

    // 🔹 2. Масив об'єктів
    const int SIZE = 3;
    Complex arr[SIZE];

    cout << "\nEnter 3 complex numbers:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nElement " << i + 1 << endl;
        arr[i].Read();
    }

    cout << "\nArray elements:\n";
    for (int i = 0; i < SIZE; i++) {
        arr[i].Display();
    }

    // 🔹 3. Демонстрація операцій
    Complex result;

    result = b.add(c);
    cout << "\nb + c = ";
    result.Display();

    result = b.subtract(c);
    cout << "b - c = ";
    result.Display();

    result = b.multiply(c);
    cout << "b * c = ";
    result.Display();

    // 🔹 4. Демонстрація get/set
    a.setReal(10);
    a.setImag(20);

    cout << "\nObject a after set: ";
    a.Display();

    cout << "Real part via get: " << a.getReal() << endl;
    cout << "Imag part via get: " << a.getImag() << endl;

    return 0;
}