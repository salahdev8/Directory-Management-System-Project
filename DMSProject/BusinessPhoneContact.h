/* File name : businessPhoneContact.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.
*/

#pragma once
#ifndef BusinessPhoneContact_H_
#define BusinessPhoneContact_H_

#include <string>
#include"Business.h"

using std::string;

class BusinessPhoneContact : public Business {

private:
	string phonenumber;
	string phonenumber2;
public:
	BusinessPhoneContact( const std::string & phnbr = "none", const std::string & phnbr2 = "none", const std::string & name = "none", const std::string & dept = "none");
	BusinessPhoneContact(const Business & bs, const std::string & phnbr = "none", const std::string & phnbr2 = "none");

	string getBusinessPhone();

	virtual void display() const;

};





#endif