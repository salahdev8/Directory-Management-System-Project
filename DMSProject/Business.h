/* File name : business.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.
*/


#pragma once
#ifndef Business_H_
#define Business_H_
#include <string>
#include"Contact.h"

using std::string;


class Business : public Contact {

private:
	
	string department;
public:
	Business(const std::string & name = "none", const std::string & dept = "none");
	Business(const Contact & ct, const std::string & dept = "none");

	string getcategory();

	virtual void display() const;

};




#endif