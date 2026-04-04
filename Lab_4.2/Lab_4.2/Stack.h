#pragma once
#include "IList.h"

class Stack : public IList {
private:
    int* data;
    int size;
    int capacity;

public:
    Stack(int cap = 10);
    ~Stack();

    void add(int value) override;
    int remove() override;
    void printType() override;
};