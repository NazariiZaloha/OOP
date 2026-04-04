#include "Queue.h"

Queue::Queue(int cap) {
    capacity = cap;
    size = 0;
    front = 0;
    data = new int[capacity];
}

Queue::~Queue() {
    delete[] data;
}

void Queue::add(int value) {
    if (size < capacity) {
        data[size++] = value;
    }
}

int Queue::remove() {
    if (front < size) {
        return data[front++]; // FIFO
    }
    return -1;
}

void Queue::printType() {
    cout << "This is Queue" << endl;
}