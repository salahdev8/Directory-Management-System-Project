/* File name : businessaddresscontact.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/

#include "BusinessAddressContact.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;



BusinessAddressContact::BusinessAddressContact(const std::string & zc, const std::string & name,  const std::string & dept,  const std::string & str, const std::string & cityname, const std::string & st) :Business(name, dept)
{
	
	street = str;
	city = cityname;
	state = st;
	zipcode = zc;
}


BusinessAddressContact::BusinessAddressContact(const Business & bs, const std::string & zc, const std::string & str, const std::string & cityname, const std::string & st) :Business(bs)
{
	
	street = str;
	city = cityname;
	state = st;
	zipcode = zc;

}

string BusinessAddressContact::getbusinessAddress()
{
	return this->street;
}

string BusinessAddressContact::getbusinessDistrict()
{
	return this->city;
}

string BusinessAddressContact::getbusinessState()
{
	return this->state;
}

string BusinessAddressContact::getbusinessZipcode()
{
	return this->zipcode;
}

void BusinessAddressContact::display() const
{
	cout << "**************************\n";
	cout << "**********Business Address**********\n";
	Business::display();
	
	cout << "Street :" << street << endl;
	cout << "City :" << city << endl;
	cout << "State :" << state << endl;
	cout << "zipcode :" << zipcode << endl;
	cout << "**************************\n\n\n";
}