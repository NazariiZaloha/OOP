#include "List.h"

List::List(int cap) {
    capacity = cap;
    size = 0;
    data = new int[capacity];
}

List::~List() {
    delete[] data;
}