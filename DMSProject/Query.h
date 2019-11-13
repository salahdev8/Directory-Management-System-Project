#pragma once
#ifndef Query_H_
#define Query_H_
#include"DMS.h"
#include<queue>


class Query{
	
	int id;
	int type;
	int pTime;


public:
	Query();
	Query(int id);
	Query(int id, int type, int pTime);
	Query(const Query &);

	int getId();
	int getType();
	int getpTime();

	void setId(int nbr);
	void settype(int nbr);
	void setpTime(int nbr);

	
	void process(DMS dms);
};

void generate_query_queue(int & queriesnbr, std::queue<Query>& queryQueue);



#endif



