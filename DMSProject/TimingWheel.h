#pragma once
#ifndef TimingWheel_H_
#define TimingWheel_H_

#include "Partition.h"
#include "Query.h"
#include "DMS.h"
#include<set>
#include<vector>
using std::set;
using std::vector;


const int max_delay = 9;


class TimingWheel {
	Partition * slot[max_delay + 1];


	//max_delay (max processing time of a query)
	int current_slot;
public:
	
	TimingWheel();
	int getCurrSlot();
	void setCurrSlot(int a);
	void insert(int processing_time, int Server_num, Query q);
	void schedule(DMS& dms, std::queue<Query>& queryQueue,int &qrProc,  set<int> &severset, set<int> &availbesever, set<string> &queriesset,  vector<int> & Servervect);
	void clear_curr_slot();
	bool isEmptyTW();

};

void print_status(int &qrProc, set<int> &severset, set<int> &availbesever,int &qrleft, set<string> & queriesset,int &nbr);
void print_final_statistics(int &dirsize, set<string> & Qprocessed, vector<int> & Servervect,int & nbr);
#endif