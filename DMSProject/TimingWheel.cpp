#include "TimingWheel.h"
#include <iomanip>
#include <string>
#include<iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using std::setw;
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::ostream_iterator;



TimingWheel::TimingWheel()
{

	//slot[current_slot] = new Partition [4];

	

	current_slot = 0;
	for (int i = 0;i <= max_delay;i++) {
		this->slot[i]=nullptr;
	
		
}
		
}

int TimingWheel::getCurrSlot()
{
	return this->current_slot;
}

void TimingWheel::setCurrSlot(int a)
{
	this->current_slot = a;
}

void TimingWheel::insert(int processing_time, int Server_num, Query q)
{
	 Partition *temp= new Partition(q,Server_num);

	 processing_time = (this->current_slot + processing_time) % (max_delay);
	 if (slot[processing_time] == NULL) {

		 slot[processing_time]=temp;
	 }
	 else {
		
		 temp->setNextPartition(slot[processing_time]);
		 slot[processing_time]=temp;
	 }
}

void TimingWheel::schedule(DMS & dms, std::queue<Query>& queryQueue,int &qrProc, set<int> &serverset, set<int> &availbesever, set<string> &queriesset, vector<int> & Servervect)
{
	while (slot[current_slot] != NULL) {
		Partition *temp;
		temp = slot[current_slot];

		if (!queryQueue.empty()) {
			Partition *nextPartition;
			nextPartition = new Partition(queryQueue.front(), temp->getServerNum());
			insert(nextPartition->getQuery().getpTime(), nextPartition->getServerNum(), nextPartition->getQuery());
			queryQueue.pop();
		}
		else {availbesever.insert(temp->getServerNum()); };
		serverset.insert(temp->getServerNum());
		Servervect.insert(Servervect.begin(), temp->getServerNum());
		 temp->getServerNum();
		 string str = "none";
		 int typqr = temp->getQuery().getType();

		 if(typqr==1){ str = "query1"; }
		 else if (typqr==2){ str = "query2"; }
		 else if (typqr == 3) { str = "query3"; }
		 else if (typqr == 4) { str = "query4"; }
		 else if (typqr == 5) { str = "query5"; }
		 else if (typqr == 6) { str = "query6"; }
		 
		 
		 queriesset.insert(str);
		
		 temp->getQuery().process(dms);
		qrProc++;
		slot[current_slot]=temp->getNextPartition();
	}


	
	
	
	/*
	Partition *temp;
	temp = slot[current_slot];
	//int i = 0;
	if (temp != NULL) {
		if (!queryQueue.empty()) {
			Partition *nextPartition;
			nextPartition = new Partition(queryQueue.front(), temp->getServerNum());
			insert(nextPartition->getQuery().getpTime(), nextPartition->getServerNum(), nextPartition->getQuery());
			queryQueue.pop();
		}
		else {};
		
	}
	else {}
	temp->getNextPartition().getQuery().process(dms);
	temp = temp->getNextPartition();*/
}

void TimingWheel::clear_curr_slot()
{
	Partition *temp;

	while (slot[current_slot]!= NULL) {
		temp = slot[current_slot];
		delete slot[current_slot];
		slot[current_slot] = temp;
	}
	
}

bool TimingWheel::isEmptyTW()
{
	
	for (int i = 0;i < max_delay;i=(i+1)%(max_delay+1)) {
		if (slot[i] != NULL) { return false; }
		else {};
	}

	return true;
	 
}

void print_status(int &qrProc, set<int> &severset, set<int> &availbesever, int &qrleft, set<string> & queriesset,int &nbr)
{
	ostream_iterator<int> out(cout, ",");
	ostream_iterator<string> out2(cout, ",");

	
	cout << "\n**********************************************************************************************************" << endl;
	cout << "Updated statu of the System: slot number "<<nbr <<"\n\n" << endl;
	cout <<  "Number of Queries processed:\t" << qrProc << endl;
	cout << "Servers used:\t";copy(severset.begin(), severset.end(), out);cout << "" << endl;
	cout << "Available servers:\t";copy(availbesever.begin(), availbesever.end(), out);cout << "" << endl;
	cout << "Number of Queries left:\t"<< qrleft<<endl;
	cout << "Type of queries just have been used:\t"; copy(queriesset.begin(), queriesset.end(), out2);cout << "" << endl;
	cout << "\n************************************************************************************************************\n\n" << endl;
}

void print_final_statistics(int & dirsize, set<string> & Qprocessed, vector<int> & Servervect,int &nbr)
{
	ostream_iterator<string> out2(cout, ",");


	int max = 0, mostvalue = Servervect[0];
	for (size_t i = 0;i < Servervect.size();i++)
	{
		int serveroccur = (int)count(Servervect.begin(), Servervect.end(), Servervect[i]);
		if (serveroccur > max)
		{
			max = serveroccur;
			mostvalue = Servervect[i];
		}
	}

	int min = (int)count(Servervect.begin(), Servervect.end(), Servervect[0]), lessvalue = Servervect[0];
	for (size_t i = 1;i < Servervect.size();i++)
	{
		int serveroccur = (int)count(Servervect.begin(), Servervect.end(), Servervect[i]);
		if (serveroccur < min)
		{
			min = serveroccur;
			lessvalue = Servervect[i];
		}
	}



	cout << "\n**********************************************************************************************************" << endl;
	cout << "***********************Final statistics**********************\n\n" << endl;
	cout << "Directory size:\t" << dirsize << endl;
	cout << "Total queries Processed :\t" << nbr << endl;
	cout << "Type of Queries processed:\t"; copy(Qprocessed.begin(), Qprocessed.end(), out2);cout << "" << endl;
	cout << "Server that processed max queries:\t"<<"server"<<mostvalue<<", "<<max <<" times"<< endl;
	cout << "The server that was most idle:\t" << "server" << lessvalue << ", " << min << " times" << endl;
	cout << "\n************************************************************************************************************\n\n" << endl;

}
