#include "StudentC.h"
#include <iostream>
#include <sstream>
using namespace std;
void StudentC::Init(int year, Man man)
{
    setYear(year);
    setMan(man);
}
void StudentC::Display() const
{
    cout << endl;
    man.Display();
    cout << "year of study = " << year << endl;
}
void StudentC::Read()
{
    int year;
    Man m;
    cout << endl;

    m.Read();
    cout << "year of study =  "; cin >> year;
    Init(year, m);
}


string StudentC::toString() const
{
    stringstream ss;
    ss << "Year of study= " << year << endl;

    return ss.str();
}

void StudentC::increaseYear() {
    year++;
}

void StudentC::Man::Init(string name, string gender, int age, double weight)
{
    setName(name);
    this->gender = gender;
    setAge(age);
    setWeight(weight);
}
void StudentC::Man::Display() const
{
    cout << endl;
    cout << "name = " << name << endl;
    cout << "gender = " << gender << endl;
    cout << "age = " << age << endl;
    cout << "weight = " << weight << endl;
}

void StudentC::Man::Read()
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

string StudentC::Man::toString() const
{
    stringstream ss;
    ss << "name = " << name << endl;
    ss << "gender = " << gender << endl;
    ss << "age = " << age << endl;
    ss << "weight = " << weight << endl;
    return ss.str();
}