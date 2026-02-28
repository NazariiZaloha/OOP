#include "Man.h"
#include <iostream>
#include <sstream>
using namespace std;

void Man::Init(string name, string gender, int age, double weight)
{
    setName(name);
    this->gender = gender;
    setAge(age);
    setWeight(weight);
}
void Man::Display() const
{
    cout << endl;
    cout << "name = " << name << endl;
    cout << "gender = " << gender << endl;
    cout << "age = " << age << endl;
    cout << "weight = " << weight << endl;
}

void Man::Read()
{
    string name, gender;
    int age;
    double weight;

    cout << endl;
    cout << "name =  "; cin >> name;
    cout << "gender =  "; cin >> gender;
    cout << "age =  "; cin >> age;
    cout << "weight =  "; cin >> weight;

    Init(name, gender, age, weight);
}

string Man::toString() const
{
    stringstream ss;
    ss << "name = " << name << endl;
    ss << "gender = " << gender << endl;
    ss << "age = " << age << endl;
    ss << "weight = " << weight << endl;
    return ss.str();
}