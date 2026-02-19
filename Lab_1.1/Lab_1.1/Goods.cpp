#include "Header.h"
#include <cstdlib>

using namespace std;

Goods::Goods() : first(0), second(0) {}

double Goods::getFirst() const
{
    return first;
}

int Goods::getSecond() const
{
    return second;
}

void Goods::setFirst(double value)
{
    if (value <= 0)
    {
        cout << "Error!" << endl;
        exit(1);
    }
    first = value;
}

void Goods::setSecond(int value)
{
    if (value <= 0)
    {
        cout << "Error" << endl;
        exit(1);
    }
    second = value;
}

bool Goods::Init(double price, int quantity)
{
    if (price <= 0 || quantity <= 0)
        return false;

    first = price;
    second = quantity;
    return true;
}

void Goods::Read()
{
    double price;
    int quantity;

    cout << "Enter price: ";
    cin >> price;

    cout << "Enter count: ";
    cin >> quantity;

    setFirst(price);
    setSecond(quantity);
}

void Goods::Display() const
{
    cout << "Price: " << first << endl;
    cout << "Count: " << second << endl;
    cout << "Result: " << cost() << endl;
}

double Goods::cost() const
{
    return first * second;
}

Goods makeGoods(double price, int quantity)
{
    if (price <= 0 || quantity <= 0)
    {
        cout << "Error!" << endl;
        exit(1);
    }

    Goods g;
    g.setFirst(price);
    g.setSecond(quantity);
    return g;
}
