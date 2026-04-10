#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include <new>

class ListArray {
private:
    struct Node {
        double data;
        Node* prev;
        Node* next;

        Node(double val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // 🔹 Ітератор
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node);

        double& operator*();
        Iterator& operator++(); // вперед
        Iterator& operator--(); // назад

        bool operator!=(const Iterator& other) const;
    };

    // 🔹 Конструктори
    ListArray() throw(std::bad_alloc);
    ListArray(int n, double value = 0) throw(std::bad_alloc);
    ListArray(const ListArray& other) throw(std::bad_alloc);

    // 🔹 Деструктор
    ~ListArray();

    // 🔹 Присвоєння
    ListArray& operator=(const ListArray& other);

    // 🔹 Методи
    void push_back(double val);
    void pop_back();

    int getSize() const;

    double sum() const;
    double average() const;
    double max() const;
    double min() const;

    // 🔹 Ітератори
    Iterator begin() const;
    Iterator end() const;

    // 🔹 Дружні оператори
    friend std::ostream& operator<<(std::ostream& os, const ListArray& arr);
    friend std::istream& operator>>(std::istream& is, ListArray& arr);

    friend ListArray operator+(const ListArray& a, const ListArray& b);
    friend ListArray operator-(const ListArray& a, const ListArray& b);

    friend ListArray operator*(const ListArray& a, double scalar);
    friend ListArray operator/(const ListArray& a, double scalar);
};

#endif