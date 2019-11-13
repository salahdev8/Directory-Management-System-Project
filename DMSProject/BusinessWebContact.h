/* File name : businesswecontact.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.
*/
#pragma once
#ifndef BusinessWebContact_H_
#define BusinessWebContact_H_
#include <string>
#include"Business.h"

using std::string;



class BusinessWebContact : public Business {

private:
	string email;
	string website;
public:

	BusinessWebContact( const std::string & name = "none", const std::string & dept = "none", const std::string & Bemail = "none", const std::string & website = "none");
	BusinessWebContact(const Business & bs, const std::string & Bemail = "none", const std::string & website = "none");
	string getBEmail();
	string getBWebsite();



	virtual void display() const;

};






#endif