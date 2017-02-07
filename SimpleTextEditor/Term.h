/*
Jacob Pawlak
Program 3 extra
November 29th, 2016
File: Term.h

*/

#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <string>

using namespace std;

class Term{
	public:
		// default constructor
     		Term();
		// initialize with the given query string and weight
     		Term(string q, long w);
		// compares two terms in descending order by weight
     		int byReverseWeightOrder(Term t1, Term t2);
		// compares two terms in lexicographic order by query
     		int compareTo(Term t1, Term t2);
		// compares two terms in lexicographic order but using only
        	// the first r characters of each query
     		int byPrefixOrder(Term t1, Term t2, int r);
     		//displays the term in the following format: the weight, followed by a tab key, followed by the query
		void print();
		// other member functions you need
		string getQuery();
		long getWeight();
		friend class Autocomplete;
	private:
		string query;
		long weight;
};

#endif // TERM_H
