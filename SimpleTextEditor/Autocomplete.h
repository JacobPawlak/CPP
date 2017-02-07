/*
Jacob Pawlak
CS216 Project 3 extra
November 29th, 2016
File: Autocomplete.h

*/

#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H


#include <vector>
#include <iostream>
#include "Term.h"
#include <string>

using namespace std;

class Autocomplete{

	public:

    		// inserts the newterm to the sequence
    		void insert(Term newterm);

    		// returns all terms that start with the given prefix,
        	// in descending order of weight
    		vector<Term> allMatches(string prefix);

		void selectionSort();
		void selectionSortWeight();

		//********** FOR BONUS PART **********

		Term& operator[](int x); //operator overload for index []
		void swap(Term& a, Term& b); //helper function for the quickSort
		void partition(int &l, int &r); //second helper function for the quickSort
		void quickSort(int left, int right); //the quickSort function that sorts the imdb.txt in less than .2 seconds
		int getIndexBinary(string prefix); //helper fucntion for allMatchesBinary that returns an index of a term
						   // that marches the prefix string
		Autocomplete allMatchesBinary(int startIndex, string prefix); //makes an autocomplete that contains all of the terms
									      // matching the prefix

		//********** END BONUS PART **********

    		// display all the terms
    		void print();

    		// other member functions you need
		int getSize();

		//for lab12, the two different search methods
		bool SequentialSearch(string prefix);
		bool BinarySearch(string prefix);

	private:

    		// choose your own data structure to represent the sequence of Term objects
		vector<Term> terms;
};


#endif //AUTOCOMPLETE_H

