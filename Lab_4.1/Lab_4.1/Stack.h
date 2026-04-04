#pragma once
#include "List.h"

class Stack : public List {
public:
    Stack(int cap = 10);

    void add(int value) override;
    int remove() override;
    void printType() override;
};