#include <iostream>
#include <string>
#include "Creditcard.h"

using namespace std;

CreditCard::CreditCard()
{
	number = "";
	ccv = "";
	name = "";
	expire = "";
}

CreditCard::CreditCard(string cardNum, string cardCSV, string cardName, string expDate)
{
	number = cardNum;
	ccv = cardCSV;
	name = cardName;
	expire = expDate;

}

void CreditCard::changeName(string newName)
{
	name = newName;
}

bool CreditCard::validate()
{
	string creditNumber = number;
	int odds = 0;
	int evens = 0;

	for(int i = 0; i <= 15; i++)
	{
		if(i % 2 != 0)
		{
			evens += (creditNumber[i] - '0');
		}
		if(i % 2 == 0)
		{
			int doubleCreditNumber = (creditNumber[i] - '0') * 2;

			if(doubleCreditNumber >= 10)
			{
				string sdoubleCreditNumber = to_string(doubleCreditNumber);
				doubleCreditNumber = (sdoubleCreditNumber[0] - '0') + (sdoubleCreditNumber[1] - '0');
			}

			odds += doubleCreditNumber;

		}
	}

	if((evens + odds) % 10 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int CreditCard::getCheckNumber()
{
	string creditNumber = number;
	int odds = 0;
	int evens = 0;

	for(int i = 0; i <= 15; i++)
	{
		if(i % 2 != 0)
		{
			evens += (creditNumber[i] - '0');
		}
		if(i % 2 == 0)
		{
			int doubleCreditNumber = (creditNumber[i] - '0') * 2;

			if(doubleCreditNumber >= 10)
			{
				string sdoubleCreditNumber = to_string(doubleCreditNumber);
				doubleCreditNumber = (sdoubleCreditNumber[0] - '0') + (sdoubleCreditNumber[1] - '0');
			}

			odds += doubleCreditNumber;

		}
	}

	if((evens + odds) % 10 == 0)
	{
		return (creditNumber[15] - '0');
	}
	else
	{
		int remainder = ((evens + odds) % 10);

		int checkDigit = ((((creditNumber[15] - '0') - remainder) + 10) % 10);

		return checkDigit;
	}

}

string CreditCard::getName()
{
	return name;
}

string CreditCard::getNumber()
{
	return number;
}

string CreditCard::getCSV()
{
	return ccv;
}

string CreditCard::getExpDate()
{
	return expire;
}

void CreditCard::getAll()
{
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
	cout << "CSV number: " << ccv << endl;
	cout << "Expiration Date: " << expire << endl;
	cout << endl;
}