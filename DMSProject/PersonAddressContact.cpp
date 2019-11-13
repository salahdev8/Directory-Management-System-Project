/* File name : personaddresscontact.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include "PersonAddressContact.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;




PersonAddressContact::PersonAddressContact(const std::string & zc,  const std::string & name, const std::string & gnd, const std::string & str, const std::string & cityname, const std::string & st):Person(gnd,name)
{
	
	street = str;
	city = cityname;
	state = st;
	zipcode = zc;
}

PersonAddressContact::PersonAddressContact(const Person & pr, const std::string & zc, const std::string & str, const std::string & cityname, const std::string & st) :Person(pr)
{
	
	street = str;
	city = cityname;
	state = st;
	zipcode = zc;
}

string PersonAddressContact::getPersonstreet()
{
	return this->street;
}

string PersonAddressContact::getPersoncity()
{
	return this->city;
}

string PersonAddressContact::getState()
{
	return this->state;
}

string PersonAddressContact::getPersonzipcode()
{
	return this->zipcode;
}

void PersonAddressContact::display() const
{
	cout << "**************************\n";
	cout << "**********Person Address**********\n";
	Person::display();
	
	cout << "Street :" << street << endl;
	cout << "City :" << city << endl;
	cout << "State :" << state << endl;
	cout << "zipcode :" << zipcode << endl;
	cout << "**************************\n\n\n";
}
