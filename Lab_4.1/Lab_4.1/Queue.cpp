#include "Queue.h"

Queue::Queue(int cap) : List(cap) {
    front = 0;
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