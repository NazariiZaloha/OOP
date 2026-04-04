#pragma once
#include "IList.h"

class Queue : public IList {
private:
    int* data;
    int size;
    int capacity;
    int front;

public:
    Queue(int cap = 10);
    ~Queue();

    void add(int value) override;
    int remove() override;
    void printType() override;
};