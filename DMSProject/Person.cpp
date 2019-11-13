/* File name : person.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include "Person.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



Person::Person(const std::string & gnd, const std::string & name) :Contact(name)
{
	gender = gnd;
	
}

Person::Person(const Contact & ct, const std::string & gnd) :Contact(ct)
{
	gender = gnd;
	
}

string Person::getGender()
{
	return this->gender;
}

void Person::display() const
{
	Contact::display();
	cout << "Gender :" << gender << endl;

}

