#pragma once
#include <string>
using namespace std;

class StudentC
{
private:
	int year;

	class Man {

	private:
		string name;
		int age;
		string gender;
		double weight;

	public:

		string getName() const { return name; }
		string getGender() const { return gender; }
		int getAge() const { return age; }
		double getWeight() const { return weight; }

		void setName(string name) { this->name = name; }
		void setAge(int age) { this->age = age; }
		void setWeight(double weight) { this->weight = weight; }


		void Init(string name, string gender, int age, double weight);
		void Display() const;
		void Read();
		string toString() const;
	};

	Man man;

public:

	int getYear() const { return year; }
	Man getMan() const { return man; }

	void setYear(int year) { this->year = year; }
	void setMan(Man man) { this->man = man; }


	void Init(int year, Man man);
	void Display() const;
	void Read();
	string toString() const;

	void increaseYear();
};


