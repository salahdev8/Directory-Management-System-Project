#pragma once
#ifndef Partition_H_
#define Partition_H_

#include "Query.h"



class Partition {
	Query query;
	int Server_num;
	Partition *nextp;
public:
	// all needed accessor functions
	Partition();
	Partition(Query q,int serv);
	Query getQuery();
	int getServerNum();
	Partition *getNextPartition();

	void setQuery(Query qr);
	void setServerNum(int nbr);
	void setNextPartition(Partition *pr);
};











#endif