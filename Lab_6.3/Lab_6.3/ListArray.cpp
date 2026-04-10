#include "ListArray.h"

// 🔹 Iterator
ListArray::Iterator::Iterator(Node* node) : current(node) {}

double& ListArray::Iterator::operator*() {
    return current->data;
}

ListArray::Iterator& ListArray::Iterator::operator++() {
    current = current->next;
    return *this;
}

ListArray::Iterator& ListArray::Iterator::operator--() {
    current = current->prev;
    return *this;
}

bool ListArray::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

// 🔹 Конструктори
ListArray::ListArray() throw(std::bad_alloc)
    : head(nullptr), tail(nullptr), size(0) {
}

ListArray::ListArray(int n, double value) throw(std::bad_alloc)
    : head(nullptr), tail(nullptr), size(0) {
    for (int i = 0; i < n; i++)
        push_back(value);
}

ListArray::ListArray(const ListArray& other) throw(std::bad_alloc)
    : head(nullptr), tail(nullptr), size(0) {
    for (Node* cur = other.head; cur != nullptr; cur = cur->next)
        push_back(cur->data);
}

// 🔹 Деструктор
ListArray::~ListArray() {
    while (head)
        pop_back();
}

// 🔹 Присвоєння
ListArray& ListArray::operator=(const ListArray& other) {
    if (this != &other) {
        while (head) pop_back();

        for (Node* cur = other.head; cur != nullptr; cur = cur->next)
            push_back(cur->data);
    }
    return *this;
}

// 🔹 push/pop
void ListArray::push_back(double val) {
    Node* node = new Node(val);

    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    size++;
}

void ListArray::pop_back() {
    if (!tail) return;

    Node* temp = tail;
    tail = tail->prev;

    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    delete temp;
    size--;
}

// 🔹 Методи
int ListArray::getSize() const {
    return size;
}

double ListArray::sum() const {
    double s = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        s += cur->data;
    return s;
}

double ListArray::average() const {
    if (size == 0)
        throw std::runtime_error("Empty list");
    return sum() / size;
}

double ListArray::max() const {
    if (!head)
        throw std::runtime_error("Empty list");

    double m = head->data;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        if (cur->data > m) m = cur->data;
    return m;
}

double ListArray::min() const {
    if (!head)
        throw std::runtime_error("Empty list");

    double m = head->data;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        if (cur->data < m) m = cur->data;
    return m;
}

// 🔹 Ітератори
ListArray::Iterator ListArray::begin() const {
    return Iterator(head);
}

ListArray::Iterator ListArray::end() const {
    return Iterator(nullptr);
}

// 🔹 Ввід/вивід
std::ostream& operator<<(std::ostream& os, const ListArray& arr) {
    for (auto it = arr.begin(); it != arr.end(); ++it)
        os << *it << " ";
    return os;
}

std::istream& operator>>(std::istream& is, ListArray& arr) {
    for (auto it = arr.begin(); it != arr.end(); ++it)
        is >> *it;
    return is;
}

// 🔹 Операції
ListArray operator+(const ListArray& a, const ListArray& b) {
    if (a.size != b.size)
        throw std::invalid_argument("Different sizes");

    ListArray res;

    auto itA = a.begin();
    auto itB = b.begin();

    while (itA != a.end()) {
        res.push_back(*itA + *itB);
        ++itA; ++itB;
    }

    return res;
}

ListArray operator-(const ListArray& a, const ListArray& b) {
    if (a.size != b.size)
        throw std::invalid_argument("Different sizes");

    ListArray res;

    auto itA = a.begin();
    auto itB = b.begin();

    while (itA != a.end()) {
        res.push_back(*itA - *itB);
        ++itA; ++itB;
    }

    return res;
}

ListArray operator*(const ListArray& a, double scalar) {
    ListArray res;

    for (auto it = a.begin(); it != a.end(); ++it)
        res.push_back(*it * scalar);

    return res;
}

ListArray operator/(const ListArray& a, double scalar) {
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");

    ListArray res;

    for (auto it = a.begin(); it != a.end(); ++it)
        res.push_back(*it / scalar);

    return res;
}