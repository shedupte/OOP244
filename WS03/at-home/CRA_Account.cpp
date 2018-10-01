#include "CRA_Account.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

namespace sict
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		int odd_Arry[5] = { 0 };
		int sin_Arry[9] = { 0 };
		int temp_Sin = 0;
		int even = 0;
		int odd = 0;
		int x = 0; 
		int y = 0;
			
		if (MIN_SIN <= sin && sin <= MAX_SIN)
		{
			for (int h = 0; h < 9; h++)
			{
				sin_Arry[h] = sin % 10;
				sin /= 10;
				cout << sin_Arry[h] << endl;
				if (h % 2 == 0) 
				{
					odd_Arry[x] = sin_Arry[h];
					x++;
				}
				else 
				{
					even += sin_Arry[h];
					
				}
				cout << odd_Arry[x] << endl;
				cout << even << endl;

			}


			strncpy(family_name, familyName, max_name_length + 1);
			strncpy(given_name, givenName, max_name_length + 1);
			SIN = sin;
		}
		else
		{
			family_name[0] = '\0';
			given_name[0] = '\0';
			SIN = 0;

		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*
		int temp_Sin = SIN;
		int arry_Sin[9];
		int even = 0;
		int odd = 0;
		int sum = 0;
		int temp_sum;
		int num_Check;

		if (MIN_SIN <= sin && sin <= MAX_SIN)
		{
			strncpy(family_name, familyName, max_name_length + 1);
			family_name[max_name_length] = '\0';
			strncpy(given_name, givenName, max_name_length + 1);
			given_name[max_name_length] = '\0';
			SIN = sin;

		}
	
		for (int i = 0; i > 9; i++)
		{	
			arry_Sin[i] = temp_Sin % 10;
			temp_Sin /= 10;
		}

		for (int j = 0; j < 8; j++)
		{
			if (j % 2 == 0)
			{
				even += arry_Sin[j];
			}
			else 
			{
				int temp_odd =arry_Sin[j] * 2;
				if (temp_odd > 9) 
				{
					odd+=(temp_odd - 10) + 1;
				}
				else 
				{
					odd += arry_Sin[j];
				}
			
			}

		}
		sum = even + odd + arry_Sin[8];

		if (sum % 10 != 0) 
		{
			temp_sum = (((sum / 10) + 1)*10);
		}
		else 
		{
			temp_sum = sum;
		}

		num_Check = temp_sum - sum;
		if (num_Check == arry_Sin[8]) 
		{
			strncpy(family_name, familyName, max_name_length + 1);
			family_name[max_name_length] = '\0';
			strncpy(given_name, givenName, max_name_length + 1);
			given_name[max_name_length] = '\0';
			SIN = sin;

		}
		else
		{
			family_name[0] = '\0';
			given_name[0] = '\0';
			SIN = 0;

		}
		*/
	}





	bool CRA_Account::isEmpty() const
	{
		return (SIN==0);
	}

	void CRA_Account::set(int year, double balance)
	{
		for (int i = 0; i < max_yrs; i++)
		{
			if (!isEmpty())
			{
				tax_return_years[i] = year;
				yearly_balance[i] = balance;
			}
		}
	}




	void CRA_Account::display() const
	{
		if (isEmpty() == 0)
		{
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name: " << given_name << endl;
			cout << "CRA Account: " << SIN << endl;

			for (int i = 0; i < max_yrs; i++)
			{
				if (yearly_balance[i] > 2) 
				{
					cout << "Year " << tax_return_years[i] << " balance owning: AMOUNT" << yearly_balance[i] << endl;
				}
				else if (yearly_balance[i] > -2)
				{
						cout << "Year " << tax_return_years[i] << " refund due: AMOUNT" << yearly_balance[i] << endl;
				
				}
				else
				{
					cout << "Year " << tax_return_years[i] << " No balance owing or refund due!" << endl;

				}


			}



		}
		else
		{
			cout << "Account object is empty!" << endl;
		}


	}


}
