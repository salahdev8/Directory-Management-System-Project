/* File name : Driver.cpp
Author: SALAH MELLOUKI
DATE:11/25/2018
Compiler used: microsoft visual studio.*/
#include <iostream>
#include <fstream>
#include "PersonAddressContact.h"
#include "PersonPhoneContact.h"
#include "PersonEmailContact.h"
#include "BusinessAddressContact.h"
#include "BusinessPhoneContact.h"
#include "BusinessWebContact.h"
#include "DMS.h"
#include "Query.h"
#include <string>
#include <iomanip>
#include <set>
#include<vector>
#include<queue>
#include <ctime>
#include <iterator>
#include <algorithm>
#include "TimingWheel.h"
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;
using std::string;




int main()

{
	DMS dms;
	int file_count, servernbr, queriesnbr;
	string *file_names = new string[6];
	
	get_user_input(file_count,file_names,servernbr,queriesnbr);

	for (int i = 0; i < file_count; i++) {
		try {
			dms.populateDirectory(file_names[i]);
		}
		catch (exception e) {
			cout << "Unable to read from file!" << endl;
		}
	}

	
	queue<Query> queryQueue;
	srand(time(NULL));

	generate_query_queue(queriesnbr, queryQueue);
	

	TimingWheel TW;
	
	for (int j = 0;j < servernbr; j++) {
		
		TW.insert(queryQueue.front().getpTime(),j+1, queryQueue.front());
		queryQueue.pop();
	}
	int queriesleft=queriesnbr;
	set<int> availbesever;

	set<string> Qprocessed;
	vector<int> Servervect;

	int totalqueries = 0;

	while (!TW.isEmptyTW())
	{
		set<int> serverset;
		set<string> queriesset;
		int qrProc=0;
		int time_slot = TW.getCurrSlot();
		TW.schedule(dms,queryQueue,qrProc,serverset, availbesever,queriesset,Servervect);
		
		
		

	   queriesleft = queriesleft - qrProc;
	   print_status(qrProc,serverset,availbesever,queriesleft, queriesset,time_slot); //new routine to be written
		
	   totalqueries = totalqueries + qrProc;


	   Qprocessed.insert(queriesset.begin(), queriesset.end());
	   


	   TW.clear_curr_slot(); //part 3 routine

	time_slot = (time_slot+1) % (max_delay+1);
	TW.setCurrSlot(time_slot);

		//total_simulation_time++;
		
	Sleep(1000);
		
	}
	int dirsize = dms.getIndex();


	print_final_statistics(dirsize,Qprocessed,Servervect,totalqueries);

	/*
	DMS dms;
	int file_count;
	char response;
	string userinput,fname,lname;

	cout << "Enter the number of input files: " << endl;
	cin >> file_count;
	string *file_names = new string[file_count];
	cout << "Enter the file names: " << endl;
	for (int i = 0; i < file_count; i++) {
		cin >> file_names[i];
		try {
			dms.populateDirectory(file_names[i]);
			
		}

		catch (exception e) {
			cout << "Unable to read from file!" << endl;
		}
	}




	//This section should be replaced by an interactive menu
	cout << "\n\n\nHello human! This is a list of queries, type the number of query you would like to try:" << endl;
	cout << "\n\n 1-Find the number of a specific name of persons in the directory ordered by state." << endl;
	cout << "\n   2-Find the number of people in the directory whose email domain is (chosen by you, ex:com,edu...) ordered by the gender." << endl;
	cout << "\n   3-Find the number of organizations in the directory whose phone number start with the area code (chosen by you, ex:205,475..) ordered by the organization category." << endl;
	cout << "\n   4-Find the number of organizations in the directory with a (chosen by you, ex:com,org,net...) email or a (chosen by you) website ordered by the organization category." << endl;
	cout << "\n   5-Display the details of an organization." << endl;
	cout << "\n   6-Display the details of a person." << endl;




	cin >> response;
	while (response != 'n') {
		if (response == '1') {
			cout << "Enter the common first name of persons you are looking for: " << endl;
			cin >> userinput;
			dms.contactRate(userinput);
		}

		else if (response == '2') {
			cout << "Enter email domain (ex:edu,com,org..): " << endl;
			cin >> userinput;
			dms.emailquery(userinput);
		}

		else if (response == '3') {
			cout << "Enter the area code (ex:205,475..): " << endl;
			cin >> userinput;
			dms.businessPhonePrefix(userinput);
		}

		else if (response == '4') {
			cout << "Enter email or website domain (ex:edu,com,org..): " << endl;
			cin >> userinput;
			dms.businessWebsufix(userinput);

		}

		else if (response == '5') {
			cout << "Enter the name of organization: " << endl;
			cin >> userinput;
			dms.displayBuiness(userinput);
		}

		else if (response == '6') {
			cout << "Enter the first name of person: " << endl;
            cin >> fname;
			cout << "Enter the lastname name of person: " << endl;
			cin >> lname;

			userinput = fname + " " + lname;
			dms.displayPerson(userinput);
		}

		else { cout << "Enter a number between 1 and 6, or enter n to stop" << endl; }
				
		cout << "Querying the Directory Management System(DMS). Enter n to stop." << endl;
		cin >> response;
	}
	cout << "Exiting the Directory Management System." << endl;




	*/











	/*Contact *dir[6];

	dir[0] = new PersonAddressContact();
	dir[1] = new PersonPhoneContact();
	dir[2] = new PersonEmailContact();
	dir[3] = new BusinessAddressContact();
	dir[4] = new BusinessPhoneContact();
	dir[5] = new BusinessWebContact();



	for (int i = 0; i < 6; i++)
	{
		dir[i]->display(); // polymorphic method

	
	}*/

	
	
	
	
	/*DMS dms1;
	
	dms1.populateBusinessDirectory("inputBusiness.txt");	
    
	dms1.populateDirectory("inputBusiness.txt");
	dms1.displayB();
	dms1.businessPhonePrefix("203");
	cout << "\n\n";
	dms1.businessWebsufix("com");
	cout << "\n\n";
	dms1.displayBuiness("Microsoft");
	*/

	/*
	DMS dms;
	dms.displayP();
	
	dms.populateDirectory("inputPerson.txt");
	dms.populatePersonDirectory("inputPerson.txt");

	dms.contactRate("Freya");
	cout << "\n\n";
	dms.emailquery("org");
	cout << "\n\n";
	dms.displayPerson("Joshua Berry");
		*/
		return 0;
}
