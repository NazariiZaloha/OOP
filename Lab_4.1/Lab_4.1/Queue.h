#pragma once
#include "List.h"

class Queue : public List {
private:
    int front;

public:
    Queue(int cap = 10);

    void add(int value) override;
    int remove() override;
    void printType() override;
};