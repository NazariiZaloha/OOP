#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <new>

class Array {
private:
    double* data;
    int low, high;
    int size;

public:
    // 🔹 Конструктор без аргументів
    Array() throw(std::bad_alloc);

    // 🔹 Конструктор з межами
    Array(int low, int high) throw(std::bad_alloc);

    // 🔹 Конструктор з ітераторами
    Array(double* begin, double* end) throw(std::bad_alloc);

    // 🔹 Конструктор копіювання
    Array(const Array& other) throw(std::bad_alloc);

    // 🔹 Деструктор
    ~Array();

    // 🔹 Оператор присвоєння
    Array& operator=(const Array& other);

    // 🔹 Індексування
    double& operator[](int index);
    const double& operator[](int index) const;

    // 🔹 Методи
    int getSize() const;

    double max() const;
    double min() const;
    double sum() const;
    double average() const;

    // 🔹 Дружні оператори
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
    friend std::istream& operator>>(std::istream& is, Array& arr);

    friend Array operator+(const Array& a, const Array& b);
    friend Array operator-(const Array& a, const Array& b);

    friend Array operator*(const Array& a, double scalar);
    friend Array operator/(const Array& a, double scalar);
};

#endif