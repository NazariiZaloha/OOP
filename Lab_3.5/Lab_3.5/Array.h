#pragma once
#include <iostream>
#include <cstdlib>

class Array {
protected:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    void rangeCheck(int index) const;

public:
    Array(int n = 0, int initValue = 0);

    int& operator[](int index);
    int getSize() const;

    void input();
    void output() const;
};