
#ifndef B1_H
#define B1_H
#include <iostream>

class B1 {
protected:
    int b1;
public:
    B1(int val);
    ~B1();
    virtual void show();
    int getB1() const { return b1; }
};
#endif