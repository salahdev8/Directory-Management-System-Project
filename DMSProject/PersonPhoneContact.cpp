/* File name : personphonecontact.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include "PersonPhoneContact.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



PersonPhoneContact::PersonPhoneContact(const std::string & phnbrh, const std::string & phnbrw, const std::string & name,const std::string & gnd) :Person(gnd,name)
{
	homephonenumber = phnbrh;
	workphonenumber = phnbrw;
}

PersonPhoneContact::PersonPhoneContact(const Person & pr, const std::string & phnbrh, const std::string & phnbrw)
{
	homephonenumber = phnbrh;
	workphonenumber = phnbrw;
}

string PersonPhoneContact::getPersonPhone()
{
	if (this->homephonenumber.compare("none") != 0) {
		return homephonenumber;
	}
	else return workphonenumber;
}



void PersonPhoneContact::display() const
{
	cout << "**************************\n";
	cout << "**********Person Phone**********\n";
	Person::display();
	cout << "Home Phone Number :" << homephonenumber << endl;
	cout << "Work Phone Number :" << workphonenumber << endl;
	cout << "**************************\n\n\n";
}

