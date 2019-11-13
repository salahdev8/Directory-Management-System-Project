/* File name : Business.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/


#include "Business.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



Business::Business(const std::string & name, const std::string & dept) :Contact(name)
{
	department = dept;
}

Business::Business(const Contact & ct,  const std::string & dept) : Contact(ct)
{
	
	department = dept;
}

string Business::getcategory()
{
	return this->department;
}

void Business::display() const
{
	Contact::display();
	cout << "Department name:" << department << endl;
	
}