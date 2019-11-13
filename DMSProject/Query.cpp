#include "Query.h"
#include<iostream>

using std::cout;
using std::endl;
using std::string;



Query::Query()
{
	this->id = 0;
	this->pTime = 0;
	this->type = 0;
}

Query::Query(int id)
{
	this->id = id;
	this->pTime = 0;
	this->type = 0;
}

Query::Query(int id, int type, int pTime)
{
	this->id = id;
	this->type = type;
	this->pTime = pTime;
}

Query::Query(const Query & qr)
{
	this->id = qr.id;
	this->pTime = qr.pTime;
	this->type = qr.type;
}



int Query::getId()
{
	return this->id;
}

int Query::getType()
{
	return this->type;
}

int Query::getpTime()
{
	return this->pTime;
}

void Query::setId(int nbr)
{
	this->id = nbr;
}

void Query::settype(int nbr)
{
	this->type = nbr;
}

void Query::setpTime(int nbr)
{
	this->pTime = nbr;
}





void generate_query_queue(int &queriesnbr,std::queue<Query>& queryQueue)
{
	for (int i = 1;i <= queriesnbr;i++) {
		int type = rand() % 6 + 1;
		int pTime = rand() % 8 + 1;
		Query qr;
		qr.setId(i);
		qr.settype(type);
		qr.setpTime(pTime);
		queryQueue.push(qr);
	}
}

void Query::process(DMS dms)
{
	int n =this->type;
	if (n==0){}
	else if (n == 1) { 
		dms.contactRate("Freya");
		 }
	else if (n==2){ 
		dms.emailquery("org");
		 }
	else if(n==3){
		dms.businessPhonePrefix("203");
	}
	else if(n==4){ 
		
		dms.businessWebsufix("org");
	}
	else if(n==5){ 
		dms.displayPerson("Freya Mcdaniel");
	}
	else if (n == 6) {
		dms.displayBuiness("Microsoft");
	}
	else { cout << "error no such type of query exist" << endl; }

}

