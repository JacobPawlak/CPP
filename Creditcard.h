#ifndef CREDITCARD_H
#define CREDIDCARD_H

#include<string>
#include<iostream>

using namespace std;

class CreditCard{

	public:

		CreditCard(); //basic constructor

		CreditCard(string number, string ccv, string name, string expDate); //constructs a credit Card with the number, ccv, and name

		bool validate(); //validates the card number using the 16-digit algorithm

		void changeName(string newName); //change the name on the card

		int getCheckNumber(); //gives the correct check number of the card

		string getName(); //gives the name of the card holder

		string getNumber(); //gives the card number

		string getCSV(); //gives the ccv number

		string CreditCard::getExpDate(); //gives the expiration date

		void getAll(); //gives all the information, name, number and ccv

	private:

		string number;
		string ccv;
		string name;
		string expire;



};

#endif