/*
Jacob Pawlak
CS216
Program 3 w/ extra part
November 29th, 2016
File: Autocomplete.cpp

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Autocomplete.h"
#include "Term.h"

using namespace std;

//inserts the Term into the vector in the back, it will get sorted later
void Autocomplete::insert(Term newterm)
{
	terms.vector::push_back(newterm);
}

//goes through the given Autocomplete vector, and picks out all of the terms that have the same prefix
// as the given prefix
vector<Term> Autocomplete::allMatches(string prefix)
{
	//init the returning vector
	vector<Term> matches;

	//run through the terms vec
	for(int i = 0; i < terms.size(); i++)
	{
		//init a temp Term
		Term temp = terms[i];
		//get the query for easy access
		string match = temp.query;
		//find the length of the prefix
		int len = prefix.length();

		//note: the first index in the query is a tab key, so we ignore the first one and go from
		// 1 to the length of the prefix. it all works out.
		if(match.substr(1, len) == prefix)
		{
			//if they match, no pun intended, put the term in the matches vector
			matches.vector::push_back(temp);
		}
	}
	//return the matches vector
	return matches;
}


//classic selection sort for the query in terms
void Autocomplete::selectionSort()
{
	//init the place holder ints
	int i, j, first;
	//make a temp Term for swapping
	Term temp;
	//get the length of the vector
	int len = terms.size();
	//start at the back of the vector for the target
	for(i = (len - 1); i > 0; i--)
	{
		//swapping procedure
		first = 0;
		for(j = 1; j <= i; j++)
		{
			//if the first is less than the j'th Term, move to the next placeholder
			if(terms[j].query > terms[first].query)
			{
				first = j;
			}

			//swap
			temp = terms[first];
			terms[first] = terms[i];
			terms[i] = temp;
		}
	}
	return;
}


//same thing for the weight
void Autocomplete::selectionSortWeight()
{
	//init the placeholder ints
	int i, j, first;
	//init a temp Term
	Term temp;
	//get the length of the terms vector
	int len = terms.size();

	//same selection sort as the one above, but with the weights, in descending order
	for(i = len - 1; i > 0; i--)
	{
		first = 0;
		for(j = 1; j <= i; j++)
		{
			//here's the weights
			if(terms[j].weight < terms[first].weight)
			{
				first = j;
			}

			//swap the terms here
			temp = terms[first];
			terms[first] = terms[i];
			terms[i] = temp;
		}
	}
	return;
}

//BONUS PART FUNCTIONS

//The operator overload for indexing
Term& Autocomplete::operator[](int x){
	return terms[x];
}

//helper function swap for the quickSort
void Autocomplete::swap(Term& a, Term& b){
	//make a temp Term for the swapping
	Term temp = a;
	a = b;
	b = temp;

}

//the second helper function for quickSort
void Autocomplete::partition(int &l, int &r){

	//provides a pivot point to check the left and right terms against
	string pivot = terms[l].query;

	while(r > l){
		while(terms[l].query < pivot) ++l;
		while(pivot < terms[r].query) --r;

		if(l > r) continue;
		//swaps terms
		swap(terms[l], terms[r]);
		++l;
		--r;
	}

}

//the quick sort function that makes the sorting go so fast
void Autocomplete::quickSort(int left, int right){

	//init a copy of the left and right that are passed in the function
	int l = left;
	int r = right;

	//split the list
	partition(l , r);

	if(left < r)//recursively call quick sort on the larger lists
		quickSort(left, r);
	if(l < right)
		quickSort(l, right);

}

//helper function for the allMatches Binary searcher
int Autocomplete::getIndexBinary(string prefix){

	int mid;
	int first = 0;
	int last = terms.size() - 1;
	//standard binary search, only here we are comparing the query member of each term
	// to the prefix passed into the function
	while(first <= last){
		//get the center of the list
		mid = (first + last) / 2;
		int len = prefix.length();
		Term temp = terms[mid];
		string match = temp.query;
		string str = match.substr(1, len);
		//for ease of reading ^
		if(prefix == str)
			return mid; //return the middle index (the first index where prefix == the term's query member)
		else if(prefix > str){
			first = mid + 1; //if its larger, look on the right side
		}
		else{ // if its smaller, look on the left side
			last = mid - 1;
		}
	}

	return -1; //if the prefix is not found in the list, return -1

}

//this is a cool function that takes the index given from the function above
// and searches left and right from that index to fill the list of matching terms
Autocomplete Autocomplete::allMatchesBinary(int startIndex, string prefix){

	//init a left and a right bound, where worst case scenario there is only one
	// match to the prefix, and in that case we want to get just that term
	int left = startIndex;
	int right = left + 1;

	//here is where we check both the left direction and the right direction
	bool complete = true;
	while(complete){
		//searching left
		int len = prefix.length();
                Term temp = terms[left];
                string match = temp.query;
                string str = match.substr(1, len);
		//again for ease of reading ^
		if(str == prefix)
			left--; // if the term matches the prefix we move the left index down 1
		else{
			left++; // to compensate for an over shoot
			complete = false; // break from the loop
		}
	}

	complete = true; // reset the bool to be true, and start the right direction searching

	while(complete){

		int len = prefix.length();
                Term temp = terms[right];
                string match = temp.query;
                string str = match.substr(1, len);
                if(str == prefix)
                        right++; // if the term matches the prefix move the right index up 1
                else{
                        right--; // again to compensate for an overshoot
                        complete = false; //break from the loop
                }

	}

	Autocomplete matches; //init the Autocomplete that needs to be returned

	for(int i = left; i <= right; i++)
		matches.insert(terms[i]); //loop from the left index to the right index to fill the
					  // autocomplete

	return matches; // return the autocomplete

}


//END BONUS PART FUNCTIONS



//regular getSize
int Autocomplete::getSize()
{
	return terms.size();
}


// The following 2 functions were used for lab 12 and are not actually used in this program

bool Autocomplete::SequentialSearch(string prefix){
	bool found = false;

	for(int i = 0; i < terms.size(); i++){

		if(found)
			break;
		else{

			//init a temp Term
                	Term temp = terms[i];
                	//get the query for easy access
                	string match = temp.query;
                	//find the length of the prefix
                	int len = prefix.length();

                	if(match.substr(0, len) == prefix)
                	{
                	        //if they match, set the flag to true so it can break
				found = true;
				cout<<"The matched term:"<<endl;
				temp.print();
                	}

		}

	}

	return found;

}

bool Autocomplete::BinarySearch(string prefix){

	int mid, left = 0;
	int right = terms.size() - 1;
	while(left < right){

		mid = left + (right - left + 1)/2;
		Term temp = terms[mid];
		string match = temp.query;
		int len = prefix.length();
		if(match.substr(0, len) > prefix){
			right = mid - 1;
		}
		else if(match.substr(0, len) < prefix){
			left = mid;
		}
		else if(match.substr(0, len) == prefix){
			cout<<"The matched term:"<<endl;
                        temp.print();
			return true;
                }

	}

	return false;
}


//print function
void Autocomplete::print()
{	//run through the Autocomplete vector and print out the terms's weight and query
	for(int i = 0; i < terms.size(); i++)
	{
		cout << terms[i].weight << "\t" << terms[i].query << endl;
	}
}

