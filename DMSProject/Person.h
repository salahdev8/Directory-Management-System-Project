/* File name : Person.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/


#pragma once
#ifndef Person_H_
#define Person_H_
#include <string>
#include"Contact.h"

using std::string;

class Person : public Contact {

private:
	
	string gender;

public:

	Person( const std::string & gnd = "not specified",  const std::string & name = "not specified");
	Person(const Contact & ct,  const std::string & gnd = "not specified");
	string getGender();
	virtual void display() const;
};


#endif