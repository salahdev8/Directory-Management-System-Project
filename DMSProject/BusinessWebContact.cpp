/* File name : businesswebcontact.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include "BusinessWebContact.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



BusinessWebContact::BusinessWebContact( const std::string & name, const std::string & dept , const std::string & Bemail, const std::string & bwebsite) :Business(name,dept )
{
	email = Bemail;
	website = bwebsite;

}

BusinessWebContact::BusinessWebContact(const Business & bs, const std::string & Bemail, const std::string & bwebsite) :Business(bs)
{
	email = Bemail;
	website = bwebsite;
}

string BusinessWebContact::getBEmail()
{
	return email;
}

string BusinessWebContact::getBWebsite()
{
	return website;
}

void BusinessWebContact::display() const
{
	cout << "**************************\n";
	cout << "**********Business web and email**********\n";
	Business::display();
	cout << "Email : " << email << endl;
	cout << "Website : " << website << endl;
	cout << "**************************\n\n\n";
}
