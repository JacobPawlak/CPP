#include <iostream>
#include <string>
#include "Creditcard.h"

using namespace std;

int main()
{

	int numNewCards = 0;

	cout << "How many new Credit cards do you want (less than 21): ";
	cin >> numNewCards;
	cout << endl;

	CreditCard cards[20];

	for(int i = 0; i < numNewCards; i++)
	{
		string newName = "";
		string newNumber = "";
		string newCSV = "";
		string month = "";
		string year = "";

		cout << "what is your first name? ";
		cin >> newName;
		cout << "what is the (16 digit) card number? ";
		cin >> newNumber;
		while(newNumber.length() != 16)
		{
			cout << "That's not the right number of digits. Please try again" << endl;
			cout << "what is the (16 digit) card number? ";
			cin >> newNumber;
		}
		cout << "what is the ccv number? ";
		cin >> newCSV;

		while(newCSV.length() != 3)
		{
			cout << "That's not the right number of digits. Please try again" << endl;
			cout << "what is the ccv number? ";
			cin >> newCSV;
		}

		cout << "what is the expiration month? (mm)";
		cin >> month;
		cout << "what is the expiration year? (yy)";
		cin >> year;

		string expDate = month + "/" + year;

		cout << endl;

		CreditCard newCard = CreditCard(newNumber, newCSV, newName, expDate);
		cards[i] = newCard;

	}

	for(int j = 0; j < numNewCards; j++)
	{
		cards[j].getAll();
		bool valid = cards[j].validate();
		if(valid)
		{
			cout << "Your card is valid." << endl;
			cout << endl;
		}
		else
		{
			int checker = cards[j].getCheckNumber();
			cout << "Your card is invalid, the last digit should be: " << checker << "." << endl;
			cout << endl;
		}
	}


	system("pause");
	return 1;
}