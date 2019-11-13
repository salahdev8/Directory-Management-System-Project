/* File name : businessAddressContact.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.
*/


#pragma once
#ifndef BusinessAddressContact_H_
#define BusinessAddressContact_H_

#include"Business.h"
#include <string>

using std::string;


class BusinessAddressContact : public Business {

private:
	
	string street;
	string city;
	string state;
	string zipcode;

public:

	BusinessAddressContact(const std::string & zc = "none", const std::string & name = "none", const std::string & dept = "none", const std::string & str = "none", const std::string & cityname = "none", const std::string & st = "none");
	BusinessAddressContact(const Business & bs, const std::string & zc = "none", const std::string & str = "none", const std::string & cityname = "none", const std::string & st = "none");

	string getbusinessAddress();
	string getbusinessDistrict();
	string getbusinessState();
	string getbusinessZipcode();


	virtual void display() const;

};




#endif