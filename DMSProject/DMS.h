/* File name : DMS.h
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.
*/#pragma once
#ifndef DMS_H_
#define DMS_H_
#include <string>
#include"Contact.h"
#include"PersonEmailContact.h"
#include"PersonPhoneContact.h"
#include "PersonAddressContact.h"
#include"BusinessWebContact.h"
#include"BusinessPhoneContact.h"
#include "BusinessAddressContact.h"


using std::string;


class DMS {

private:

	Contact* contacts[1000];
	int index;
	
public:
	
	
	DMS();
	DMS(const DMS &ct);
	
    //~DMS();
	
	
	int getIndex();
	void populateDirectory(const std::string & filename);
	void populatePersonDirectory(const std::string & filename, int  ctnbr );
	void populateBusinessDirectory(const std::string & filename, int  ctnbr);
	void displayP();
	void displayB();
	
	
	void contactRate(const std::string & ctname);
	void emailquery(const std::string & str);

	void businessPhonePrefix(const std::string & str);
	void businessWebsufix(const std::string & str);


	void displayPerson(const std::string & ctname);
	void displayBuiness(const std::string & businessname);
};

void get_user_input(int &inputfilenbr, string *filenames,int &servernbr,int &queriesnbr );

#endif