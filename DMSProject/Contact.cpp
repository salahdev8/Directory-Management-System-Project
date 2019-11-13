/* File name : contact.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include "Contact.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



Contact::Contact(const std::string & name )
{
	
	contactname = name;
}

string Contact::getcontactname()
{
	return this->contactname;
}


void Contact::display() const
{

	
	cout << "Contact name: " << contactname << endl;

}

