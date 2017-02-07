/*
Jacob Pawlak
Project 3 extra
Novermber 29th, 2016
CS216
File: main.cpp

requires: Term.h Autocomplete.h

*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include "Term.h"
#include "Autocomplete.h"

using namespace std;

int main(int argc, char** argv)
{
	//init a file type
	ifstream infile;
	//init the Autocomplete class vector called myList
	Autocomplete myList;

	//if the user doesnt have the right number of comand line arguments give an error and return
	if(argc != 3)
	{
		cout << "There need to be two command line arguements: <input file name> <number of desired query results>" << endl;
		return 2;
	}
	//if the second command line arguement is negative or 0, error and return
	if((*argv[2] == '0') || (*argv[2] == '-'))
	{
		cout << "You need to have a positive number (integer that does not start with 0) of desired query results" << endl;
		return 2;
	}
	//cast the char to an int and subtract it's ascii value
	int r = *argv[2] - '0';

	//try to open the file from the command line
	infile.open(argv[1]);
	//if it doesnt work, error and return
	if(!infile.good())
	{

		cout << "Error opening file... " << argv[1] << " ...please try again" << endl;
		return 2;
	}

	//init the string for the line by line reading
	string line;
	//read through the file
	while(getline(infile, line))
	{
		istringstream ss(line);
		//init the query and weight values for the Term
		string qdata = "";
		long wdata = 0;
		ss >> wdata;
		getline(ss, qdata);
		//make a new Term and insert it into myList
		Term t = Term(qdata, wdata);
		myList.insert(t);
	}

	//look at time

	clock_t tstart, tstop;
        tstart = clock();
	myList.quickSort(0, myList.getSize() - 1);
        tstop = clock();
        double  elapsed = (tstop-tstart)/((double) (CLOCKS_PER_SEC));
	//display the time it takes to quickSort
        cout << fixed << "Time for quick sorting... "<<  elapsed << " seconds." << endl;

	//take in user query values until they type exit
	while(true)
	{
		//init a string for the query
		string quer = "";
		//ask the user for the query string
		cout << "Please input the search query(type \"exit\" to quit): ";
		getline(cin, quer);
		//if the query is exit, thank the user and return
		if(quer == "exit")
		{
			cout << "thank you for using the program!" << endl;
			return 1;
		}
		else
		{

			//make a new vector of Terms and fill it with the allMatchesBinary sorted Terms

			int startIndex = myList.getIndexBinary(quer); //find the first index in myList where term.query == quer

			if(startIndex == -1){ //if getIndexBinary returns -1, there is no term that matches quer

				cout << "sorry, there is no entry matching: " << quer << endl;
				continue; //continue back to the while loop and ask the user for the next query

			}

			//start clock again here
			tstart = clock();
                	Autocomplete matches = myList.allMatchesBinary(startIndex, quer);
			//matches is the new Autocomeplete that has all the matches to quer,
			// it is then sorted by weight
			matches.selectionSortWeight();
			//stop clock here
			tstop = clock();
			//display time here
			elapsed = (tstop-tstart)/((double) (CLOCKS_PER_SEC));
        		cout << fixed << "Time for searching... "<<  elapsed << " seconds." << endl;

			//print from the matches vector until you get to the specified ammount of queries
			for(int i = 0; i < matches.getSize(); i++)
			{
				if(i >= r)
				{
					//break here
					break;
				}

				//matches is already sorted in allMatches(blah) function
				matches[i].print();

			}

		}

	}

	//exit the program
	return 1;
}
