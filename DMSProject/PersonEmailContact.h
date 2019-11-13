/* File name : personemailcontact.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/

#pragma once
#ifndef PersonEmailContact_H_
#define PersonEmailContact_H_
#include <string>
#include"Person.h"

using std::string;


class PersonEmailContact : public Person {

private:
	string email;
	string email2;
public:

	PersonEmailContact( const std::string & name = "none", const std::string & gnd = "not specified", const std::string & Pemail = "none", const std::string & Pemail2 = "none2");
	PersonEmailContact(const Person & pr, const std::string & Pemail = "none", const std::string & Pemail2 = "none2");

	string getPersonEmail();
	virtual void display() const;

};


#endif