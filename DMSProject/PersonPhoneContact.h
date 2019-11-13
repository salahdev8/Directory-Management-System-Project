/* File name : personphonecontact.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/


#pragma once
#ifndef  PersonPhoneContact_H_
#define  PersonPhoneContact_H_
#include <string>
#include"Person.h"

using std::string;


class PersonPhoneContact : public Person {

private:
	string homephonenumber;
	string workphonenumber;
public:

	
	PersonPhoneContact( const std::string & phnbr = "none", const std::string & phnbr2 = "none", const std::string & name = "none", const std::string & gnd = "not specified");
	PersonPhoneContact(const Person & pr, const std::string & phnbr = "none", const std::string & phnbr2 = "none");
	string getPersonPhone();
	virtual void display() const;

};



#endif