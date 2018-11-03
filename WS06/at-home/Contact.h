/*
Name:Tenzin Shedup
Student number:120664180
Email:tshedup@myseneca.ca
Workshop:Week_6
Date:Sept 29,2018
*/

#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_

namespace sict
{
	const int MAX_CHAR=20;
	class Contact 
	{
		char m_Name[MAX_CHAR];
		long long* m_PhoneNumbers;
		int m_NoPhoneNumbers;

		bool ValidCheck(const long long );
	
	public:
		Contact();
		Contact(const char*, const long long*, const int);
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
		~Contact();
		bool isEmpty() const;
		void display() const;

	
	};
}
#endif