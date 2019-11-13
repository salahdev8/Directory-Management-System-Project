/* File name : businessphonecontact.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/

#include "BusinessPhoneContact.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



BusinessPhoneContact::BusinessPhoneContact( const std::string & phnbr, const std::string & phnbr2, const std::string & name, const std::string & dept ) :Business(name,dept)
{
	phonenumber = phnbr;
	phonenumber2 = phnbr2;

}

BusinessPhoneContact::BusinessPhoneContact(const Business & bs, const std::string & phnbr, const std::string & phnbr2) :Business(bs)
{
	phonenumber = phnbr;
	phonenumber2 = phnbr2;
}

string BusinessPhoneContact::getBusinessPhone()
{
	if (this->phonenumber.compare("none") != 0) {
		return phonenumber;
	}
	else return phonenumber2;
}

void BusinessPhoneContact::display() const
{
	cout << "**************************\n";
	cout << "**********Business Phone**********\n";
	Business::display();
	cout << "First Phone Number : " << phonenumber << endl;
	cout << "Second Phone Number : " << phonenumber2 << endl;
	cout << "**************************\n\n\n";
}