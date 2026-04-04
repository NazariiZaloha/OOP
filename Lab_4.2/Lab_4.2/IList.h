#pragma once
#include <iostream>
using namespace std;

class IList {
public:
    virtual void add(int value) = 0;
    virtual int remove() = 0;
    virtual void printType() = 0;

    virtual ~IList() {}
};