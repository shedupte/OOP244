/*
Name:Tenzin Shedup
Student number:120664180
Email:tshedup@myseneca.ca
Workshop:Week_6
Date:Sept 29,2018
*/
#define _CRT_SERCURE_NO_WARNINGS
#include "Contact.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace sict {

	bool sict::Contact::ValidCheck(const long long num)// checks to see if the phone number passed is valid
	{
		bool key;
		string Num = to_string(num);
		int NumLength = Num.length();
		if (NumLength > 12 || NumLength < 11 || Num[NumLength - 7] == 0 || Num[NumLength - 10] == 0 || Num[0] == 0)//check to see if last condition is met 
		{
			key = false;
		}
		else
		{
			key = true;
		}
		return key;
	}

	sict::Contact::Contact()
	{
		m_Name[0] = '\0';
		m_PhoneNumbers = nullptr;
		m_NoPhoneNumbers = 0;
	}

	sict::Contact::Contact(const char *name, const long long *phoneNumbers, const int noPhoneNumbers)
	{
		if (name != nullptr && name[0] != '\0')
		{
			strncpy(m_Name, name, 20);// store names into object
			m_Name[20] = '\0';// last index for null terminator
		}
		else
		{
			m_Name[0] = '\0';
		}
		if (phoneNumbers != nullptr && noPhoneNumbers > 0)
		{
			m_PhoneNumbers = new long long[noPhoneNumbers];
			m_NoPhoneNumbers = 0;
			for (int i = 0; i < noPhoneNumbers; i++)
			{
				if (ValidCheck(phoneNumbers[i]))
				{
					m_PhoneNumbers[m_NoPhoneNumbers] = phoneNumbers[i];
					m_NoPhoneNumbers++;

				}
			}
		}
		else 
		{
			m_PhoneNumbers = nullptr;
			m_NoPhoneNumbers = 0;
		}
	}

	Contact::Contact(const Contact & contact)
	{
		m_PhoneNumbers = nullptr;
		*this = contact;
	}

	Contact & Contact::operator=(const Contact &contact)
	{
		if (this != &contact) 
		{
			strcpy(m_Name, contact.m_Name);
			m_NoPhoneNumbers = contact.m_NoPhoneNumbers;
			delete[] m_PhoneNumbers;
			if (contact.m_PhoneNumbers != nullptr) 
			{
				m_PhoneNumbers = new long long[m_NoPhoneNumbers];
				for (int i = 0; i < m_NoPhoneNumbers; i++) 
				{
					m_PhoneNumbers[i] = contact.m_PhoneNumbers[i];
				}
			}
			else 
			{
				m_PhoneNumbers = nullptr;
			}
		}
		return *this;
	}

	Contact & Contact::operator+=(long long phoneNumber)
	{
		bool temp_valid = ValidCheck(phoneNumber);
		if (temp_valid) 
		{
			m_NoPhoneNumbers++;

			long long* temp_phoneNumbers = new long long[m_NoPhoneNumbers];
			for (int i = 0; i < m_NoPhoneNumbers-1; i++)
			{
				temp_phoneNumbers[i] = m_PhoneNumbers[i];
			}
			temp_phoneNumbers[m_NoPhoneNumbers - 1] = phoneNumber;
			delete[] m_PhoneNumbers;
			m_PhoneNumbers=temp_phoneNumbers;
		}
		return *this;
		
	}

	sict::Contact::~Contact()
	{
		delete[] m_PhoneNumbers;
		m_PhoneNumbers = nullptr;
	}

	bool sict::Contact::isEmpty() const
	{
		bool key = (m_Name[0] == '\0' || m_Name == nullptr);

		return key;
	}

	void sict::Contact::display() const
	{
		if (isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << m_Name << endl;
			for (int i = 0; i < m_NoPhoneNumbers; i++)
			{
				string TempNum = to_string(m_PhoneNumbers[i]);
				int NumSize = TempNum.length();
				string oCountryCode = TempNum.substr(0, NumSize - 10);//country code part 
				string oAreaCode = TempNum.substr(NumSize - 10, 3);//area code part
				string oMidPhoneNum = TempNum.substr(NumSize - 7, 3);//the middle digits
				string oEndPhoneNum = TempNum.substr(NumSize - 4);//the last digits

				cout << "(+" << oCountryCode << ") " << oAreaCode << " " << oMidPhoneNum << "-" << oEndPhoneNum << endl;



			}

		}
	}
}
