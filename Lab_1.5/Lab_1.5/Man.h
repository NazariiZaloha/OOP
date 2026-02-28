#pragma once
#include <string>
using namespace std;
class Man
{
private:
	string name;
	int age;
	string gender;
	double weight;
public:

	string getName() const { return name; }
	string getGender() const { return gender;  }
	int getAge() const { return age; }
	double getWeight() const { return weight; }

	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; } 
	void setWeight(double weight) { this->weight = weight;  }


	void Init(string name, string gender, int age, double weight );
	void Display() const;
	void Read();
	string toString() const;
};
