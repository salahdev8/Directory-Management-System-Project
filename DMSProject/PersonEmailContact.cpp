/* File name : personemailcontact.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include "PersonEmailContact.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



PersonEmailContact::PersonEmailContact(const std::string & name, const std::string & gnd, const std::string & Pemail, const std::string & Pemail2) :Person(gnd,name)
{
	email = Pemail;
	email2 = Pemail2;
}

PersonEmailContact::PersonEmailContact(const Person & pr, const std::string & Pemail, const std::string & Pemail2) : Person(pr)
{
	email = Pemail;
	email2 = Pemail2;
}

string PersonEmailContact::getPersonEmail()
{
	if (this->email.compare("none") != 0) {
		return email;
	}
	else return email2;
}

void PersonEmailContact::display() const
{
	cout << "**************************\n";
	cout << "**********Person Email**********\n";
	Person::display();
	cout << "Email :" << email << endl;
	cout << "Email secondary:" << email2 << endl;
	cout << "**************************\n\n\n";
}




