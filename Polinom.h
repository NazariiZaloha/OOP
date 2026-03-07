#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Polinom {
private:
    double coeffs[100];  
    int size;            
    int count;           

    void updateCount();  

public:
    
    Polinom();  
    Polinom(int n, double arr[] = nullptr);  
    Polinom(const Polinom& other);         
    Polinom(const string& s);               

  
    double getCoeff(int i) const;
    void setCoeff(int i, double value);
    int getSize() const;
    int getCount() const;

    
    Polinom& operator=(const Polinom& other);

    
    Polinom& operator+=(const Polinom& other);
    Polinom& operator-=(const Polinom& other);
    Polinom& operator*=(const Polinom& other);

    
    double& operator[](int i);

    
    double evaluate(double x) const;    
    Polinom derivative() const;        
    Polinom integral() const;         
    operator string() const;         
    void print() const;                 
    void printSize() const;       
};


Polinom operator+(Polinom a, const Polinom& b);
Polinom operator-(Polinom a, const Polinom& b);
Polinom operator*(Polinom a, const Polinom& b);

bool operator==(const Polinom& a, const Polinom& b);
bool operator!=(const Polinom& a, const Polinom& b);

istream& operator>>(istream& in, Polinom& p);
ostream& operator<<(ostream& out, const Polinom& p);