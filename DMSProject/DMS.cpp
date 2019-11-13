/* File name : DMS.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include "DMS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <typeinfo>

#pragma once

using namespace std;
using std::string;



DMS::DMS()
{
	*contacts = new Contact[100];
	index = 0;
}

DMS::DMS(const DMS &ct)
{
	index = ct.index;
	for (int i = 0; i < index; i++)
	contacts[i] = ct.contacts[i];
}

/*
DMS::~DMS()
{
	delete[] contacts;
}*/



int DMS::getIndex()
{
	return this->index;
}

void DMS::populateDirectory(const std::string & filename)
{
	ifstream file;
	file.open(filename);
	string line1;

	if (!file)
	{
		cout << "Error opening output file" << endl;
		system("pause");

	}

	else { getline(file, line1, '\n'); }

	

		string word = "";
		string temp[2];
		int j = 0;
		for (auto x : line1)
		{

			if (x == ',')
			{
				temp[j] = word;
				word = "";
				j++;

			}
			else
			{
				word = word + x;
			}

		}
		temp[j] = word;

		if (temp[1].compare("person") == 0) {
			int ctnbr = std::stoi(temp[0]);
			this->populatePersonDirectory(filename, ctnbr);
		}
		else if (temp[1].compare("business") == 0) {
			int ctnbr = std::stoi(temp[0]);
			this->populateBusinessDirectory(filename, ctnbr);
		}
	}


void DMS::populatePersonDirectory(const std::string & filename,  int  ctnbr)
{
	ifstream file;
	file.open(filename);
	string line1;
	string *linestable;
	string  **lineselments;

	
	linestable = new string [ctnbr+1];
	lineselments = new string *[ctnbr+1];

	for (int i = 0;i <= ctnbr;i++) {
		lineselments[i] = new string[9];
	}

	if (!file)
	{
		cout << "Error opening output file" << endl;
		system("pause");

	}
	int i = 0;
	int e = 0;
	while (!file.eof())
	{
		getline(file, line1, '\n');
		linestable[e] = line1;
		e++;
	}
	
	int count = 0;
	int *Tcounter;
	Tcounter = new int[ctnbr];
	for (int str = 1; str < e;str++) {

		string word = "";
		string *temp;
		temp= new string[ctnbr];
		int j = 0;
		int w = 1;
		for (auto x : linestable[str])
		{

			if (x == ',')
			{
				temp[j] = word;
				word = "";
				j++;
				w++;
			}
			else
			{
				word = word + x;
			}

		}
		temp[j] = word;
		Tcounter[count] = w;


		for (int a = 0;a <9;a++) {
			lineselments[count][a] = temp[a];
		}count++;
	}
	

	for (int i = 0;i < count;i++) {
	
		int colsize = Tcounter[i];
		
		if(colsize>7){
		if (colsize == 9) {
			string name = lineselments[i][0];
			string gender = lineselments[i][1];
			string phone1 = lineselments[i][2];
			string email1 = lineselments[i][3];
			string street = lineselments[i][4]+","+lineselments[i][5];
			string city = lineselments[i][6];
			string state = lineselments[i][7];
			string zipcode = lineselments[i][8];

			this->contacts[index] = new PersonPhoneContact(phone1, "", name, gender);
			this->index++;

			this->contacts[index] = new PersonEmailContact(name, gender, email1, "");
			this->index++;

			
			this->contacts[index] =  new PersonAddressContact(zipcode, name, gender, street, city, state);
			this->index++;

		}
		else if (colsize == 8) {
			string name = lineselments[i][0];
			string gender = lineselments[i][1];
			string phone1 = lineselments[i][2];
			string email1 = lineselments[i][3];
			string street = lineselments[i][4];
			string city = lineselments[i][5];
			string state = lineselments[i][6];
			string zipcode = lineselments[i][7];

			
			this->contacts[index] = new PersonPhoneContact(phone1,"", name, gender);
			this->index++;

			this->contacts[index] = new PersonEmailContact(name, gender, email1,"");
			this->index++;
			
			this->contacts[index] = new PersonAddressContact(zipcode, name, gender, street, city, state);
			this->index++;
		}
		}

		/*else if (colsize <= 7) {

			string name = lineselments[i][0];

			for(int i=0;)

		}*/

	}
	

	

	cout << "Person Directory populated with success!" << endl;
		
}

void DMS::populateBusinessDirectory(const std::string & filename,int ctnbr)
{
	ifstream file;
	file.open(filename);
	string line1;
	string *linestable;
	string  **lineselments;


	linestable = new string[ctnbr + 1];
	lineselments = new string *[ctnbr + 1];

	for (int i = 0;i <= ctnbr+1;i++) {
		lineselments[i] = new string[10];
	}


	if (!file)
	{
		cout << "Error opening output file" << endl;
		system("pause");

	}
	int i = 0;
	int e = 0;
	while (!file.eof())
	{
		getline(file, line1, '\n');
		linestable[e] = line1;
		e++;
	}

	int count = 0;
	int *Tcounter;
	Tcounter = new int[ctnbr];

	for (int str = 1; str < e;str++) {

		string word = "";
		string *temp;
		temp = new string[ctnbr];
		int j = 0;
		int w = 1;
		for (auto x : linestable[str])
		{

			if (x == ',')
			{
				temp[j] = word;
				word = "";
				j++;
				w++;
			}
			else
			{
				word = word + x;
			}

		}
		temp[j] = word;
		Tcounter[count] = w;
		for (int a = 0;a <= 9;a++) {
			lineselments[count][a] = temp[a];
		}count++;
	}
	


	for (int i = 0;i < count;i++) {
		
		int colsize = Tcounter[i];

		if (colsize > 8) {
			if (colsize == 10) {
				string name = lineselments[i][0];
				string departmnent = lineselments[i][1];
				string phone1 = lineselments[i][2];
				string email1 = lineselments[i][3];
				string website = lineselments[i][4];
				string street = lineselments[i][5] + "," + lineselments[i][6];
				string city = lineselments[i][7];
				string state = lineselments[i][8];
				string zipcode = lineselments[i][9];

				this->contacts[index] = new BusinessPhoneContact(phone1, "", name, departmnent);
				this->index++;

				this->contacts[index] = new BusinessWebContact(name,departmnent, email1,website);
				this->index++;


				this->contacts[index] = new BusinessAddressContact(zipcode, name, departmnent, street, city, state);
				this->index++;

			}
			else if (colsize == 9) {
				string name = lineselments[i][0];
				string departmnent = lineselments[i][1];
				string phone1 = lineselments[i][2];
				string email1 = lineselments[i][3];
				string website = lineselments[i][4];
				string street = lineselments[i][5];
				string city = lineselments[i][6];
				string state = lineselments[i][7];
				string zipcode = lineselments[i][8];


				this->contacts[index] = new BusinessPhoneContact(phone1, "", name, departmnent);
				this->index++;

				this->contacts[index] = new BusinessWebContact(name, departmnent, email1, website);
				this->index++;


				this->contacts[index] = new BusinessAddressContact(zipcode, name, departmnent, street, city, state);
				this->index++;
			}
		}

		/*else if (colsize <= 7) {

			string name = lineselments[i][0];

			for(int i=0;)

		}*/
	}

	cout << "Business Directory populated with success!"<<endl;
}

void DMS::displayP()
{
	for (int i = 0;i <= this->index;i++) {

		this->contacts[i]->display();
	}
}

void DMS::displayB()
{
	for (int i = 0;i <= this->index;i++) {

		this->contacts[i]->display();
	}
}







void DMS::contactRate(const std::string & fname)
{
	
	vector<string> statvect;
	set<string> statset;
	

	for (int i = 0;i < this->index;i++) {
		string cName;
		cName = this->contacts[i]->getcontactname();

		string word = "";
		string temp[10];
		int j = 0;
		int w = 1;
		for (auto x : cName)
		{

			if (x == ' ')
			{
				temp[j] = word;
				word = "";
				j++;
				w++;
			}
			else
			{
				word = word + x;
			}

		}
		temp[j] = word;
		

		if (temp[0].compare(fname) == 0) {
			
			PersonAddressContact* PAC;
	
			PAC = dynamic_cast<PersonAddressContact*>(this->contacts[i]);
			if (PAC) {
				
				
				statvect.insert(statvect.begin(), PAC->getState());
				statset.insert(PAC->getState());
				
			}
			else {}
		}else {}
	}
	

	set <string>::iterator it;

	cout << "\n************Query 1***********\n" << endl;
	cout << "Number of \"" << fname << "\" in the directory ordered by state:\n" << endl;
	cout << setw(7) << "State" << setw(15) << "Number"  << endl << endl;

	for (it = statset.begin(); it != statset.end(); it++)
	{
		cout << setw(5) << *it << setw(14) << count(statvect.begin(), statvect.end(), *it) << endl;
	}

	cout << "\n*****************************\n" << endl;
}

void DMS::emailquery(const std::string & str)
{

	
	vector<string> statvect;
	set<string> statset;
	

	for (int i = 0;i < this->index;i++) {
		
		
			
			PersonEmailContact* PEC;
	
			PEC = dynamic_cast<PersonEmailContact*>(this->contacts[i]);
			if (PEC) {
				
				string email=PEC->getPersonEmail();

					string word = "";
					string temp[10];
					int j = 0;
					int w = 1;
					for (auto x : email)
					{

						if (x == '.')
						{
							temp[j] = word;
							word = "";
							j++;
							w++;
						}
						else
						{
							word = word + x;
						}

					}
					temp[j] = word;



					for (int e = 0;e < 10;e++) {

						if (str.compare(temp[e]) == 0) {

							statvect.insert(statvect.begin(), PEC->getGender());
							statset.insert(PEC->getGender());

						}
						else {}
					}
			}

				
				
			
			else {}
		}

	set <string>::iterator it;

	cout << "\n************Query 2***********\n" << endl;
	cout << "Number of people in the directory whose email domain is \""<< str<< "\" ordered by the gender :\n" << endl;
	cout << setw(7) << "gender" << setw(15) << "Number" << endl << endl;

	for (it = statset.begin(); it != statset.end(); it++)
	{
		cout << setw(7) << *it << setw(15) << count(statvect.begin(), statvect.end(), *it) << endl;
	}

	cout << "\n**************************\n\n" << endl;
}

void DMS::businessPhonePrefix(const std::string & str)
{

	vector<string> statvect;
	set<string> statset;


	for (int i = 0;i < this->index;i++) {



		BusinessPhoneContact* BPC;

		BPC = dynamic_cast<BusinessPhoneContact*>(this->contacts[i]);
		if (BPC) {

			string phone = BPC->getBusinessPhone();

			string word = "";
			string temp[10];
			int j = 0;
			int w = 1;
			for (auto x : phone)
			{

				if (x == '-')
				{
					temp[j] = word;
					word = "";
					j++;
					w++;
				}
				else
				{
					word = word + x;
				}

			}
			temp[j] = word;



			for (int e = 0;e < 10;e++) {

				if (str.compare(temp[e]) == 0 && str.compare(temp[1]) == 0) {

					statvect.insert(statvect.begin(), BPC->getcategory());
					statset.insert(BPC->getcategory());
					
				}
				else {}
			}
		}




		else {}
	}

	set <string>::iterator it;

	cout << "\n************Query 3***********\n" << endl;
	cout << "number of organizations in the directory whose phone number start with the area code \"" << str << "\" ordered by the organization category :\n" << endl;
	cout << setw(10) << "Category" << setw(15) << "Number" << endl << endl;

	for (it = statset.begin(); it != statset.end(); it++)
	{
		cout << setw(10) << *it << setw(15) << count(statvect.begin(), statvect.end(), *it) << endl;
	}

	cout << "\n*************************\n\n" << endl;
}

void DMS::businessWebsufix(const std::string & str)
{
	vector<string> statvect;
	set<string> statset;


	for (int i = 0;i < this->index;i++) {



	    BusinessWebContact* BWC;

		BWC = dynamic_cast<BusinessWebContact*>(this->contacts[i]);
		if (BWC) {

			string email = BWC->getBEmail();
			string website = BWC->getBWebsite();

			string word = "";
			string temp[10];
			int j = 0;
			int w = 1;
			for (auto x : email)
			{

				if (x == '.')
				{
					temp[j] = word;
					word = "";
					j++;
					w++;
				}
				else
				{
					word = word + x;
				}

			}
			temp[j] = word;



			string mot = "";
			string temp2[10];
			int q = 0;
			
			for (auto x : website)
			{

				if (x == '.')
				{
					temp2[q] = mot;
					mot = "";
					q++;
				
				}
				else
				{
					mot = mot + x;
				}

			}
			temp2[q] = mot;






			for (int e = 0;e < 10;e++) {

				if (str.compare(temp[e]) == 0 || str.compare(temp2[e]) == 0) {

					statvect.insert(statvect.begin(), BWC->getcategory());
					statset.insert(BWC->getcategory());

				}
				else {}
			}
		}




		else {}
	}

	set <string>::iterator it;

	cout << "\n************Query 4***********\n" << endl;
	cout << "number of organizations in the directory with a\"" << str << "\" email or a \""<< str <<"\"website ordered by the organization category. :\n" << endl;
	cout << setw(17) << "Category" << setw(15) << "Number" << endl << endl;

	for (it = statset.begin(); it != statset.end(); it++)
	{
		cout << setw(17) << *it << setw(15) << count(statvect.begin(), statvect.end(), *it) << endl;
	}

	cout << "\n***************************\n\n" << endl;
}

void DMS::displayPerson(const std::string & ctname)
{
	string contacfullname;
	string contactgender;
	string contactemail;
	string contactphone;
	string contactaddressatreet;
	string contactdisrict;
	string contactstate;
	string contactzip;



	for (int i = 0;i < this->index;i++) {
		string cName;
		

		cName = this->contacts[i]->getcontactname();

		if (cName.compare(ctname) == 0) {


			PersonEmailContact* PEC;
			PersonPhoneContact* PPC;
			PersonAddressContact* PAC;

			PEC = dynamic_cast<PersonEmailContact*>(this->contacts[i]);
			PPC = dynamic_cast<PersonPhoneContact*>(this->contacts[i]);
			PAC = dynamic_cast<PersonAddressContact*>(this->contacts[i]);


			if (PEC) {

				contacfullname = PEC->getcontactname();
				contactgender = PEC->getGender();
				contactemail = PEC->getPersonEmail();
			}

			else if (PPC) {

				contactphone = PPC->getPersonPhone();

			}
			else if (PAC) {

				contactaddressatreet = PAC->getPersonstreet();
				contactdisrict = PAC->getPersoncity();
				contactstate = PAC->getState();
				contactzip = PAC->getPersonzipcode();
			}

			else {}

		}
	}

	cout << "\n************Query 5***********\n" << endl;

	cout << "Display the details of :" << ctname <<"\n"<<endl;
	cout << "Name :\t" << contacfullname << endl;
	cout << "Gender :\t" << contactgender << endl;
	cout << "Email :\t" << contactemail << endl;
	cout << "Phone Number :\t" << contactphone << endl;
	cout << "Address :\t" << endl;
	cout << "\t Street :\t" <<contactaddressatreet << endl;
	cout << "\t District :\t" << contactdisrict << endl;
	cout << "\t State :\t" << contactstate << endl;
	cout << "\t Zip :\t" << contactzip << endl;

	cout << "\n***************************\n\n" << endl;
}

void DMS::displayBuiness(const std::string & businessname)
{
	string bname;
	string businesscategory;
	string businessemail;
	string businesswebsite;
	string businessphone;
	string businessaddressatreet;
	string businessdisrict;
	string businessstate;
	string businesszip;



	for (int i = 0;i < this->index;i++) {
		string Name;




		Name = this->contacts[i]->getcontactname();

		if (Name.compare(businessname) == 0) {


			 BusinessWebContact* BWC;
			BusinessPhoneContact* BPC;
			BusinessAddressContact* BAC;

			BWC = dynamic_cast<BusinessWebContact*>(this->contacts[i]);
			BPC = dynamic_cast<BusinessPhoneContact*>(this->contacts[i]);
			BAC = dynamic_cast<BusinessAddressContact*>(this->contacts[i]);


			if (BWC) {

				bname = BWC->getcontactname();
				businesscategory = BWC->getcategory();
				businessemail = BWC->getBEmail();
				businesswebsite = BWC->getBWebsite();

			}

			else if (BPC) {

				businessphone = BPC->getBusinessPhone();

			}
			else if (BAC) {

				businessaddressatreet = BAC->getbusinessAddress();
				businessdisrict = BAC->getbusinessDistrict();
				businessstate = BAC->getbusinessState();
				businesszip = BAC->getbusinessZipcode();
			}

			else {}

		}
	}
	cout << "\n************Query 6***********\n" << endl;
	cout << "Display the details of :" << businessname << "\n" << endl;
	cout << "Name :\t" << businessname << endl;
	cout << "Category :\t" << businesscategory << endl;
	cout << "Email :\t" << businessemail << endl;
	cout << "Website :\t" << businesswebsite << endl;
	cout << "Phone Number :\t" << businessphone << endl;
	cout << "Address :\t" << endl;
	cout << "\t Street :\t" << businessaddressatreet << endl;
	cout << "\t District :\t" << businessdisrict << endl;
	cout << "\t State :\t" << businessstate << endl;
	cout << "\t Zip :\t" << businesszip << endl;
}

void get_user_input(int & inputfilenbr, string * filenames, int & servernbr, int & queriesnbr)
{

	cout << "Enter the number of input files: " << endl;
	cin >> inputfilenbr;


	cout << "Enter the file names: " << endl;
	for (int i = 0; i < inputfilenbr; i++) {
		cin >> filenames[i];
	}

	cout << "Enter number of servers : " << endl;
	cin >> servernbr;
	cout << "Enter the number of queries: " << endl;
	cin >> queriesnbr;

	


}
