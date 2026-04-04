#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

public:
    Array(int size = 0, unsigned char value = 0);
    virtual ~Array() {}

    int getSize() const;
    void rangeCheck(int index) const;

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    virtual Array* add(const Array& other) const; // віртуальна функція
    virtual void print() const;
    virtual const char* getType() const;
};

#endif