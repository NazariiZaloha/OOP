#include "Goods.h"


Goods::Goods()
{
    first = 0;
    second = 0;
}

Goods::Goods(double f, int s)
{
    first = f;
    second = s;
}

Goods::Goods(const Goods& g)
{
    first = g.first;
    second = g.second;
}

void Goods::Init(double f, int s)
{
    first = f;
    second = s;
}

double Goods::getFirst() const { return first; }
int Goods::getSecond() const { return second; }

void Goods::setFirst(double f) { first = f; }
void Goods::setSecond(int s) { second = s; }

double Goods::cost() const
{
    return first * second;
}

Goods::operator string() const
{
    return "Price=" + to_string(first) +
        " Quantity=" + to_string(second);
}


Goods& Goods::operator++()
{
    first++;
    return *this;
}

Goods Goods::operator++(int)
{
    Goods t(*this);
    second++;
    return t;
}


Goods& Goods::operator--()
{
    first--;
    return *this;
}

Goods Goods::operator--(int)
{
    Goods t(*this);
    second--;
    return t;
}


Goods& Goods::operator=(const Goods& g)
{
    first = g.first;
    second = g.second;
    return *this;
}


ostream& operator<<(ostream& out, const Goods& g)
{
    out << "Price: " << g.first
        << " Quantity: " << g.second
        << " Cost: " << g.cost();
    return out;
}


istream& operator>>(istream& in, Goods& g)
{
    cout << "Price: ";
    in >> g.first;
    cout << "Quantity: ";
    in >> g.second;
    return in;
}


Goods makeGoods(double f, int s)
{
    Goods g(f, s);
    return g;
}