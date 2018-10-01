#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CRA_Account.h"
#include <cstring>

using namespace std;

namespace sict 
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		if (MIN_SIN <= sin && sin <= MAX_SIN) 
		{
			strncpy(family_name, familyName, max_name_length+1);
			strncpy(given_name, givenName, max_name_length+1);
			SIN = sin;
		}
		else
		{
			family_name[0] = '\0';
			given_name[0] = '\0';
			SIN = 0;

		}
	}
	


	bool CRA_Account::isEmpty() const
	{
		return(SIN == 0);
	}



	void CRA_Account::display() const 
	{
		if (isEmpty()==0) 
		{
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << given_name << endl;
			cout << "CRA Account: " << SIN << endl;
		}
		else
		{
			cout << "Account object is empty!" << endl;
		}


	}
	

}
