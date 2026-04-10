#include "Array.h"

// 🔹 Конструктор без аргументів
Array::Array() throw(std::bad_alloc) : low(0), high(-1), size(0), data(nullptr) {}

// 🔹 Конструктор з межами
Array::Array(int l, int h) throw(std::bad_alloc) {
    if (l > h)
        throw std::invalid_argument("Invalid index range");

    low = l;
    high = h;
    size = high - low + 1;

    data = new double[size](); // zero-init
}

// 🔹 Конструктор з ітераторами
Array::Array(double* begin, double* end) throw(std::bad_alloc) {
    size = end - begin;
    low = 0;
    high = size - 1;

    data = new double[size];

    for (int i = 0; i < size; i++)
        data[i] = begin[i];
}

// 🔹 Конструктор копіювання
Array::Array(const Array& other) throw(std::bad_alloc) {
    low = other.low;
    high = other.high;
    size = other.size;

    data = new double[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

// 🔹 Деструктор
Array::~Array() {
    delete[] data;
}

// 🔹 Присвоєння
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;

        low = other.low;
        high = other.high;
        size = other.size;

        data = new double[size];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    return *this;
}

// 🔹 Індексування
double& Array::operator[](int index) {
    if (index < low || index > high)
        throw std::out_of_range("Index out of range");

    return data[index - low];
}

const double& Array::operator[](int index) const {
    if (index < low || index > high)
        throw std::out_of_range("Index out of range");

    return data[index - low];
}

// 🔹 Методи
int Array::getSize() const {
    return size;
}

double Array::sum() const {
    double s = 0;
    for (int i = 0; i < size; i++)
        s += data[i];
    return s;
}

double Array::average() const {
    if (size == 0)
        throw std::runtime_error("Empty array");
    return sum() / size;
}

double Array::max() const {
    if (size == 0)
        throw std::runtime_error("Empty array");

    double m = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] > m) m = data[i];
    return m;
}

double Array::min() const {
    if (size == 0)
        throw std::runtime_error("Empty array");

    double m = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] < m) m = data[i];
    return m;
}

// 🔹 Ввід/вивід
std::ostream& operator<<(std::ostream& os, const Array& arr) {
    for (int i = arr.low; i <= arr.high; i++)
        os << arr[i] << " ";
    return os;
}

std::istream& operator>>(std::istream& is, Array& arr) {
    for (int i = arr.low; i <= arr.high; i++)
        is >> arr[i];
    return is;
}

// 🔹 Операції з масивами
Array operator+(const Array& a, const Array& b) {
    if (a.size != b.size)
        throw std::invalid_argument("Different sizes");

    Array res(a.low, a.high);

    for (int i = 0; i < a.size; i++)
        res.data[i] = a.data[i] + b.data[i];

    return res;
}

Array operator-(const Array& a, const Array& b) {
    if (a.size != b.size)
        throw std::invalid_argument("Different sizes");

    Array res(a.low, a.high);

    for (int i = 0; i < a.size; i++)
        res.data[i] = a.data[i] - b.data[i];

    return res;
}

// 🔹 Скалярні операції
Array operator*(const Array& a, double scalar) {
    Array res(a.low, a.high);

    for (int i = 0; i < a.size; i++)
        res.data[i] = a.data[i] * scalar;

    return res;
}

Array operator/(const Array& a, double scalar) {
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");

    Array res(a.low, a.high);

    for (int i = 0; i < a.size; i++)
        res.data[i] = a.data[i] / scalar;

    return res;
}