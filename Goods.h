#pragma once
#include <iostream>
#include <string>

using namespace std;

class Goods
{
private:
    double first; 
    int second;   

public:
    Goods();                      
    Goods(double f, int s);       
    Goods(const Goods& g);         

    void Init(double f, int s);
    double cost() const;

    double getFirst() const;
    int getSecond() const;

    void setFirst(double f);
    void setSecond(int s);

    operator string() const;

    Goods& operator++();   
    Goods operator++(int); 
    Goods& operator--();
    Goods operator--(int);

    Goods& operator=(const Goods& g);

    friend ostream& operator<<(ostream& out, const Goods& g);
    friend istream& operator>>(istream& in, Goods& g);
};

Goods makeGoods(double f, int s);