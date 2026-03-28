#ifndef B2_H
#define B2_H
#include <iostream>

class B2 {
protected:
    int b2;
public:
    B2(int val);
    ~B2();
    virtual void show();
};
#endif