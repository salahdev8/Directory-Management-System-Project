#include "Partition.h"



Partition::Partition()
{
	this->query = Query();
	this->Server_num = 0;
	this->nextp = NULL;

}

Partition::Partition(Query q, int serv)
{
	this->query = q;
	this->nextp = NULL;
	this->Server_num = serv;
}

Query Partition::getQuery()
{
	return this->query;
}

int Partition::getServerNum()
{
	return this->Server_num;
}

Partition * Partition::getNextPartition()
{
	return this->nextp;
}

void Partition::setQuery(Query qr)
{
	this->query = qr;
}

void Partition::setServerNum(int nbr)
{
	this->Server_num = nbr;
}

void Partition::setNextPartition(Partition * pr)
{
	if (pr == NULL)
		this->nextp = NULL;
	else
		this->nextp = pr;
	
}

