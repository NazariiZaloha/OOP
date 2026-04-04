#pragma once
#include <iostream>
using namespace std;

class List {
protected:
    int* data;
    int size;
    int capacity;

public:
    List(int cap = 10);
    virtual ~List();

    virtual void add(int value) = 0;
    virtual int remove() = 0;
    virtual void printType() = 0;
};