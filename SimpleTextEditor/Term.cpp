/*
Jacob Pawlak
Program 3 extra
CS216
File: Term.cpp

*/


#include <iostream>
#include <string>
#include "Term.h"


using namespace std;

Term::Term()	//default constructor, init all values to 0
{
	query = "";
	weight = 0;
}

Term::Term(string q, long w)	//regular constructor, init values to given
{
	query = q;
	weight = w;

}

int Term::byReverseWeightOrder(Term t1, Term t2)
{					//return 1 if this < that
					//return 0 if this == that
					//return -1 if this > that
	if(t1.weight < t2.weight)
		return 1;
	if(t1.weight == t2.weight)
		return 0;
	if(t1.weight > t2.weight)
		return -1;
}

int Term::compareTo(Term t1, Term t2)
{					 //return 1 if this < that
					 //return 0 if this == that
					 //return -1 if this > that
	if(t1.query < t2.query)
		return 1;
	if(t1.query == t2.query)
		return 0;
	if(t1.query > t2.query)
		return -1;
}

int Term::byPrefixOrder(Term t1, Term t2, int r)
{
	//this one returns 1, 0, or -1 according to the length of the prefix, and only considers the substring from 0 to r
	string t1Sub = "";
	string t2Sub = "";

	//if the query is smaller than r, just use the query
	if(t1.query.length() <= r)
	{
		t1Sub = t1.query;
	}
	//else, substring the query to match the r length (prefix)
	else
	{
		t1Sub = t1.query.substr(0,r);
	}
	//same here for the second query
	if(t2.query.length() <= r)
	{
		t2Sub = t2.query;
	}

	else
	{
		t2Sub = t2.query.substr(0,r);
	}


	if(t1Sub < t2Sub)
		return 1;
	if(t1Sub == t2Sub)
		return 0;
	if(t1Sub > t2Sub)
		return -1;
}

void Term::print() //display like: weight \t query
{
	cout << weight << "\t" << query << endl;
}


string Term::getQuery()
{
	return query;
}

long Term::getWeight()
{
	return weight;
}

