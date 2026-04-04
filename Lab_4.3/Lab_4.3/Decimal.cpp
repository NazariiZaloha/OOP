#include "Decimal.h"

Decimal::Decimal(int size, unsigned char value, int sign)
    : Array(size, value), sign(sign) {
}

Decimal* Decimal::add(const Array& other) const {
    const Decimal* d = dynamic_cast<const Decimal*>(&other);
    if (!d) throw std::invalid_argument("Wrong type for Decimal add");

    int n = std::max(size, d->getSize());
    Decimal* result = new Decimal(n);
    int carry = 0;

    for (int i = 0; i < n; i++) {
        int a = (i < size) ? data[i] : 0;
        int b = (i < d->getSize()) ? (*d)[i] : 0;
        int sum = a + b + carry;
        (*result)[i] = sum % 10;
        carry = sum / 10;
    }

    return result;
}

Decimal Decimal::operator+(const Decimal& other) const {
    Decimal* temp = add(other);
    Decimal result = *temp;
    delete temp;
    return result;
}

Decimal Decimal::operator-(const Decimal& other) const {
    Decimal result(size);
    int borrow = 0;

    for (int i = 0; i < size; i++) {
        int a = data[i];
        int b = (i < other.size) ? other.data[i] : 0;
        int diff = a - b - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else borrow = 0;
        result[i] = diff;
    }
    return result;
}

bool Decimal::operator==(const Decimal& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++)
        if (data[i] != other.data[i]) return false;
    return true;
}

bool Decimal::operator<(const Decimal& other) const {
    for (int i = size - 1; i >= 0; i--) {
        if (data[i] < other.data[i]) return true;
        if (data[i] > other.data[i]) return false;
    }
    return false;
}

void Decimal::print() const {
    if (sign == -1) std::cout << "-";
    for (int i = size - 1; i >= 0; i--)
        std::cout << (int)data[i];
    std::cout << std::endl;
}

const char* Decimal::getType() const { return "Decimal"; }