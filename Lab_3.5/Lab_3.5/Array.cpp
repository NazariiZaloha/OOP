#include "Array.h"

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        std::cerr << "Error: index out of range!\n";
        exit(1);
    }
}

Array::Array(int n, int initValue) {
    if (n < 0 || n > MAX_SIZE) {
        std::cerr << "Error: invalid array size!\n";
        exit(1);
    }
    size = n;
    for (int i = 0; i < size; i++)
        arr[i] = initValue;
}

int& Array::operator[](int index) {
    rangeCheck(index);
    return arr[index];
}

int Array::getSize() const {
    return size;
}

void Array::input() {
    std::cout << "Enter " << size << " array elements: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void Array::output() const {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}