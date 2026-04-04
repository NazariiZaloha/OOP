#include "Stack.h"

Stack::Stack(int cap) {
    capacity = cap;
    size = 0;
    data = new int[capacity];
}

Stack::~Stack() {
    delete[] data;
}

void Stack::add(int value) {
    if (size < capacity) {
        data[size++] = value;
    }
}

int Stack::remove() {
    if (size > 0) {
        return data[--size]; // LIFO
    }
    return -1;
}

void Stack::printType() {
    cout << "This is Stack" << endl;
}