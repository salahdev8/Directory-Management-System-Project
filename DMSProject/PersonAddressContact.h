/* File name : personaddresscontact.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#pragma once
#ifndef PersonAddressContact_H_
#define PersonAddressContact_H_
#include <string>
#include"Person.h"

using std::string;



class PersonAddressContact : public Person {

private:
	
	
	string street;
	string city;
	string state;
	string zipcode;

public:
	PersonAddressContact(const std::string & zc="none", const std::string & name = "none", const std::string & gnd = "not specified", const std::string & str = "none", const std::string & cityname = "none", const std::string & st = "none");
	PersonAddressContact(const Person & pr, const std::string & zc = "none", const std::string & str = "none", const std::string & cityname = "none", const std::string & st = "none");
	string getPersonstreet();
	string getPersoncity();
	string getState();
	string getPersonzipcode();
	virtual void display() const;

};






#endif