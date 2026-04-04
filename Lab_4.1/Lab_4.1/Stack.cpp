#include "Stack.h"

Stack::Stack(int cap) : List(cap) {}

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