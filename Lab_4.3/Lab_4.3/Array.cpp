#include "Array.h"

Array::Array(int size, unsigned char value) {
    if (size < 0 || size > MAX_SIZE)
        throw std::out_of_range("Invalid size");
    this->size = size;
    for (int i = 0; i < size; i++)
        data[i] = value;
}

int Array::getSize() const { return size; }

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
}

unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    rangeCheck(index);
    return data[index];
}

Array* Array::add(const Array& other) const {
    int minSize = std::min(size, other.getSize());
    Array* result = new Array(minSize);
    for (int i = 0; i < minSize; i++)
        (*result)[i] = data[i] + other[i];
    return result;
}

void Array::print() const {
    for (int i = 0; i < size; i++)
        std::cout << (int)data[i] << " ";
    std::cout << std::endl;
}

const char* Array::getType() const { return "Array"; }