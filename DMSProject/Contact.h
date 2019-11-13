/* File name : contact.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.
*/

#pragma once

#ifndef Contact_H_
#define Contact_H_
#include <string>
using std::string;


class  Contact {


private:
	string contactname;
	

public:

	
	Contact(const std::string & name = "none1");
	string getcontactname();

	virtual void display() const;
	

};

#endif