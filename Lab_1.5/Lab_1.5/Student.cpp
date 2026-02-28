#include "Student.h"
#include <iostream>
#include <sstream>
using namespace std;
void Student::Init(int year, Man man)
{
	setYear(year);
	setMan(man);
}
void Student::Display() const
{
	cout << endl;
	man.Display(); 
	cout << "year of study = " << year << endl;
}
void Student::Read()
{
	int year;
	Man m;
	cout << endl;
	
	m.Read(); 
	cout << "year of study =  "; cin >> year;
	Init(year, m);
}


string Student::toString() const
{
	stringstream ss;
	ss << "Year of study= " << year << endl;
	
	return ss.str();
}

void Student::increaseYear() {
	year++;
}